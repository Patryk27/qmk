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

    poetry2nix = {
      url = "github:nix-community/poetry2nix";

      inputs = {
        nixpkgs = {
          follows = "nixpkgs";
        };
      };
    };

    utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs = { self, qmk, nixpkgs, poetry2nix, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };

        poetry2nix' = poetry2nix.lib.mkPoetry2Nix {
          inherit pkgs;
        };

        pkgs-avr = pkgs.pkgsCross.avr;

        qmk-env = poetry2nix'.mkPoetryEnv {
          projectDir = qmk + "/nix";
        };

        firmware = pkgs-avr.runCommandLocal "firmware"
          {
            nativeBuildInputs = [
              pkgs-avr.buildPackages.gcc8
            ];
          } ''
          mkdir -p $out/qmk

          cp -ar ${qmk}/* $out/qmk
          chmod -R 777 $out/qmk/*
          sed -i '1c#!${qmk-env}/bin/python3' $out/qmk/bin/qmk
          ln -s ${./src} $out/qmk/keyboards/ergodox_ez/keymaps/custom
          $out/qmk/bin/qmk compile -kb ergodox_ez -km custom

          mv $out/qmk/ergodox_ez_custom.hex $out/firmware.hex
          rm -rf $out/qmk
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
