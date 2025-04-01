{
  inputs = {
    qmk = {
      flake = false;
      submodules = true;
      type = "git";
      url = "https://github.com/qmk/qmk_firmware";
    };

    nixpkgs = {
      url = "github:nixos/nixpkgs";
    };

    utils = {
      url = "github:numtide/flake-utils";
    };
  };

  outputs =
    {
      self,
      qmk,
      nixpkgs,
      poetry2nix,
      utils,
    }:
    utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };

        firmware =
          pkgs.runCommandLocal "firmware"
            {
              buildInputs = [ pkgs.git pkgs.qmk ];
            }
            ''
              export HOME=/tmp/qmk

              mkdir /tmp/qmk
              cp -ar ${qmk}/* /tmp/qmk
              chmod -R 777 /tmp/qmk/*
              ln -s ${./src} /tmp/qmk/keyboards/ergodox_ez/keymaps/custom

              qmk config user.qmk_home=/tmp/qmk

              SKIP_GIT=1 \
              NOT_REPO=1 \
              qmk compile -kb ergodox_ez -km custom

              mv /tmp/qmk/ergodox_ez_base_custom.hex $out
            '';

      in
      {
        defaultPackage = pkgs.writeShellScriptBin "flash" ''
          sudo ${pkgs.teensy-loader-cli}/bin/teensy-loader-cli \
              --mcu=atmega32u4 \
              -w ${firmware} \
              -v
        '';
      }
    );
}
