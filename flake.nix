{
  description = "Aerin custom cpp game engine";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
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
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        # 1. The Package (what 'nix build' does)
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "aerin";
          version = "0.1.0";
          src = ./.;

          # CMake automatically handles the build phases
          nativeBuildInputs = with pkgs; [
            cmake
            pkg-config
          ];
          buildInputs = with pkgs; [
            glfw
          ];
        };

        # 2. The Development Shell (what 'nix develop' does)
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            cmake
            pkg-config
            glfw
            clang
          ];
        };
      }
    );
}
