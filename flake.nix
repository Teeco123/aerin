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
    flake-utils.lib.eachSystem [ "x86_64-linux" "aarch64-darwin" ] (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        mkShell = pkgs.mkShell.override {
          stdenv = pkgs.llvmPackages.stdenv;
        };

        packages = with pkgs; [
          cmake
          clang-tools
          glfw
        ];

        release = pkgs.stdenv.mkDerivation {
          name = "aerin";
          version = "0.1.0";
          src = ./.;
          buildInputs = packages;
        };

        debug = pkgs.stdenv.mkDerivation {
          name = "aerin-debug";
          version = "0.1.0";
          src = ./.;
          buildInputs = packages;
          cmakeBuildType = "Debug";
        };

        shell = ''
          echo "Generating compile_commands.json..."
          rm compile_commands.json
          cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=1
          cp build/compile_commands.json compile_commands.json
          rm -rf build 
        '';

      in
      {
        packages = {
          default = debug;
          release = release;
          debug = debug;
        };

        devShells = {
          default = mkShell {
            buildInputs = packages;
            shellHook = shell;
          };
        };

        apps = {
          default = {
            type = "app";
            program = "${self.packages.${system}.default}/bin/Editor";
          };
        };
      }
    );
}
