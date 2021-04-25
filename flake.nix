# Based on;
# https://github.com/qmk/qmk_firmware/blob/611cd80861b1bd8ad57ef5b78f11a349e74b1949/shell.nix

{
  inputs = {
    qmk = {
      url = github:qmk/qmk_firmware;
      flake = false;
    };

    nixpkgs = {
      url = github:nixos/nixpkgs;
    };
  };

  outputs = { self, qmk, nixpkgs }: {
    devShell = {
      x86_64-linux =
        let
          pkgs = (import nixpkgs) {
            system = "x86_64-linux";
          };

          pkgs-avr = pkgs.pkgsCross.avr;

          avrlibc = pkgs-avr.libcCross;

          avr-includes = [
            "-isystem ${avrlibc}/avr/include"
            "-B${avrlibc}/avr/lib/avr5"
            "-L${avrlibc}/avr/lib/avr5"
            "-B${avrlibc}/avr/lib/avr35"
            "-L${avrlibc}/avr/lib/avr35"
            "-B${avrlibc}/avr/lib/avr51"
            "-L${avrlibc}/avr/lib/avr51"
          ];

          qmk-cli = pkgs.writeShellScriptBin "qmk" ''
            set -e

            if [[ ! -d .qmk ]]; then
              git clone \
                --depth 1 \
                --recurse-submodules \
                https://github.com/qmk/qmk_firmware \
                .qmk
            fi

            export GIT_DIR=.qmk/.git

            if [[ $(git rev-parse HEAD) != "${qmk.rev}" ]]; then
              git fetch
              git checkout "${qmk.rev}"
              git submodule update --recursive
            fi

            ln -s "$(pwd)/src" ./.qmk/keyboards/ergodox_ez/keymaps/custom
            trap 'rm ./.qmk/keyboards/ergodox_ez/keymaps/custom' EXIT

            ./.qmk/bin/qmk "$@"
          '';

          qmk-cli-env = pkgs.poetry2nix.mkPoetryEnv {
            projectDir = qmk + "/nix";
          };

          do-compile = pkgs.writeShellScriptBin "do-compile" ''
            ${qmk-cli}/bin/qmk compile -kb ergodox_ez -km custom
          '';

          do-flash = pkgs.writeShellScriptBin "do-flash" ''
            sudo ${qmk-cli}/bin/qmk flash -kb ergodox_ez -km custom
          '';

        in
        pkgs.mkShell {
          buildInputs = [
            do-compile
            do-flash

            avrlibc
            qmk-cli
            qmk-cli-env

            pkgs.avrdude
            pkgs.dfu-programmer
            pkgs.dfu-util
            pkgs.teensy-loader-cli

            pkgs-avr.buildPackages.binutils
            pkgs-avr.buildPackages.gcc8
          ];

          AVR_CFLAGS = avr-includes;
          AVR_ASFLAGS = avr-includes;
        };
    };
  };
}
