# Based on:
# https://github.com/qmk/qmk_firmware/blob/611cd80861b1bd8ad57ef5b78f11a349e74b1949/shell.nix

{
  inputs = {
    qmk = {
      type = "git";
      url = "https://github.com/qmk/qmk_firmware.git";
      submodules = true;
      flake = false;
    };

    nixpkgs = {
      url = "github:nixos/nixpkgs";
    };

    utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs = { self, qmk, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };

        pkgs-linux = import nixpkgs {
          system = "x86_64-linux";
        };

        pkgs-linux-avr = pkgs-linux.pkgsCross.avr;

        qmk-env = pkgs-linux.poetry2nix.mkPoetryEnv {
          projectDir = qmk + "/nix";
        };

        firmware = pkgs-linux.runCommandLocal "firmware"
          {
            nativeBuildInputs = [
              pkgs-linux-avr.buildPackages.binutils
              pkgs-linux-avr.buildPackages.gcc8
              pkgs-linux-avr.libcCross
            ];
          } ''
          if [ -d /tmp/qmk ]; then
            rm -rf /tmp/qmk
          fi

          mkdir /tmp/qmk
          cp -ar ${qmk}/* /tmp/qmk
          chmod -R 777 /tmp/qmk/*
          sed -i '1c#!${qmk-env}/bin/python3' /tmp/qmk/bin/qmk

          ln -s ${./src} /tmp/qmk/keyboards/ergodox_ez/keymaps/custom
          /tmp/qmk/bin/qmk compile -kb ergodox_ez -km custom

          mkdir $out
          mv /tmp/qmk/ergodox_ez_custom.hex $out/firmware.hex
        '';

      in
      {
        defaultPackage =
          pkgs.writeShellScriptBin "flash" ''
            sudo ${pkgs.teensy-loader-cli}/bin/teensy-loader-cli \
                --mcu=atmega32u4 \
                -w ${firmware}/firmware.hex \
                -v
          '';
      }
    );
}
