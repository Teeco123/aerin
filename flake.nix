{
  description = "Aerin custom cpp game engine";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };

  outputs =
    {
      self,
      nixpkgs,
    }:
    let
      # Boilerplate
      pkgs = nixpkgs.legacyPackages."x86_64-linux";
      mkShell = pkgs.mkShell.override {
        stdenv = pkgs.llvmPackages.stdenv;
      };

      # Project dependencies
      packages = with pkgs; [
        cmake
        clang-tools
        glfw
      ];

      # Project build versions
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

      # Dev shell hook
      shell = ''
        echo "Generating compile_commands.json..."
        rm compile_commands.json
        cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=1
        cp build/compile_commands.json compile_commands.json
        rm -rf build 
      '';

    in
    {
      packages."x86_64-linux" = {
        default = debug;
        release = release;
        debug = debug;
      };

      devShells."x86_64-linux" = {
        default = mkShell {
          buildInputs = packages;
          shellHook = shell;
        };
      };

      apps."x86_64-linux" = {
        default = {
          type = "app";
          program = "${self.packages."x86_64-linux".default}/bin/Editor"; # Adjust "aerin" to your actual binary name
        };
      };
    };
}
