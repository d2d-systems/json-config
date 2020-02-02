from conans import ConanFile, tools, CMake
import os


class JSONConfigConan(ConanFile):
    name = "JSONConfig"
    version = "0.1.0"
    description = "Lightweight JSON-based config library"
    topics = ("conan", "json", "config", "header-only")
    url = "https://github.com/d2d-systems/json-config"
    settings = "os", "compiler", "arch", "build_type"
    no_copy_source = True
    license = "BSD-3-Clause"
    options = {
    }
    default_options = {
    }
    build_requires = "gtest/1.8.1"
    requires = "nlohmann_json/3.7.3"
    generators = "cmake"
    exports = "LICENSE"
    exports_sources = ["cmake/*", "include/*", "test/*", "CMakeLists.txt"]

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy(pattern="LICENSE", dst="licenses", src=".")
        cmake = CMake(self)
        cmake.configure()
        cmake.install()
        tools.rmdir(os.path.join(self.package_folder, "lib"))

    def package_id(self):
        self.info.header_only()
