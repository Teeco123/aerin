{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };
  outputs =
    {
      self,
      nixpkgs,
      flake-utils,
    }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = import nixpkgs {
          inherit system;
          config.allowUnfree = true;
        };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            zsh
            nixfmt-rfc-style
            nil
            llvmPackages_20.clang
            cmake
          ];
        };
        packages.default = pkgs.clangStdenv.mkDerivation {
          pname = "Editor";
          version = "0.1.0";
          src = ./.;
          nativeBuildInputs = with pkgs; [
            cmake
            llvmPackages_20.clang
          ];
          configurePhase = ''
            cmake -B .build -S .
          '';

          buildPhase = ''
            cmake --build .build
            install_name_tool -add_rpath $out/lib .build/Editor/Editor
          '';

          installPhase = ''
            mkdir -p $out/lib
            cp .build/Aerin/libAerin.dylib $out/lib/

            mkdir -p $out/bin
            cp .build/Editor/Editor $out/bin/
          '';
        };
      }
    );
}
