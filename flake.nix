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
      url = github:nixos/nixpkgs/release-20.09;
    };

    utils = {
      url = github:numtide/flake-utils;
    };
  };

  outputs = { self, qmk, nixpkgs, utils }:

    utils.lib.eachSystem [ "x86_64-linux" ] (system:
      let
        pkgs = (import nixpkgs) {
          inherit system;
        };

        pkgs-avr = pkgs.pkgsCross.avr;

        qmk-env = pkgs.poetry2nix.mkPoetryEnv {
          projectDir = qmk + "/nix";
        };

        hex = pkgs.runCommandLocal "hex"
          {
            nativeBuildInputs = [
              pkgs-avr.buildPackages.binutils
              pkgs-avr.buildPackages.gcc8
              pkgs-avr.libcCross
            ];
          } ''
          cp -ar ${qmk}/* /tmp
          chmod -R 777 /tmp/*
          sed -i '1c#!${qmk-env}/bin/python3' /tmp/bin/qmk

          ln -s ${./src} /tmp/keyboards/ergodox_ez/keymaps/custom
          /tmp/bin/qmk compile -kb ergodox_ez -km custom

          mkdir $out
          mv /tmp/ergodox_ez_custom.hex $out/firmware.hex
        '';

      in
      {
        defaultPackage =
          pkgs.writeShellScriptBin "flash" ''
            sudo ${pkgs.teensy-loader-cli}/bin/teensy-loader-cli \
                --mcu=atmega32u4 \
                -w ${hex}/firmware.hex \
                -v
          '';
      }
    );
}
