cmake_minimum_required(VERSION 3.15)

project(json_config VERSION 0.1.0 LANGUAGES CXX)
option(JCONFIG_BuildTests "Build the unit tests when BUILD_TESTING is enabled." ON)
option(JCONFIG_Install "Install CMake targets during install step." ON)


if (NOT CONAN_EXPORTED)
    include(cmake/conan.cmake)
    conan_cmake_run(
            CONANFILE conanfile.py
            BASIC_SETUP
            PROFILE default
            PROFILE_AUTO ALL
    )
endif ()


include(GNUInstallDirs)
set(JCONFIG_TARGET_NAME ${PROJECT_NAME})
set(JCONFIG_TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(JCONFIG_CONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(JCONFIG_INCLUDE_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(JCONFIG_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include/")
set(JCONFIG_CMAKE_CONFIG_TEMPLATE "cmake/config.cmake.in")
set(JCONFIG_CMAKE_CONFIG_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(JCONFIG_CMAKE_VERSION_CONFIG_FILE "${JCONFIG_CMAKE_CONFIG_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
set(JCONFIG_CMAKE_PROJECT_CONFIG_FILE "${JCONFIG_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")
set(JCONFIG_CMAKE_PROJECT_TARGETS_FILE "${JCONFIG_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Targets.cmake")


add_library(${JCONFIG_TARGET_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${JCONFIG_TARGET_NAME} ALIAS ${JCONFIG_TARGET_NAME})
target_compile_features(${JCONFIG_TARGET_NAME} INTERFACE cxx_std_17)
target_include_directories(
        ${JCONFIG_TARGET_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${JCONFIG_INCLUDE_BUILD_DIR}>
        $<INSTALL_INTERFACE:include>
)
target_sources(
        ${JCONFIG_TARGET_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${JCONFIG_INCLUDE_BUILD_DIR}>/json_config.h
)


include(CTest)
if (BUILD_TESTING AND JCONFIG_BuildTests)
    enable_testing()
    add_subdirectory(test)
endif ()


include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${JCONFIG_CMAKE_VERSION_CONFIG_FILE}
        COMPATIBILITY SameMajorVersion
)
configure_file(
        ${JCONFIG_CMAKE_CONFIG_TEMPLATE}
        ${JCONFIG_CMAKE_PROJECT_CONFIG_FILE}
        @ONLY
)

if (JCONFIG_Install)
    install(
            DIRECTORY ${JCONFIG_INCLUDE_BUILD_DIR}
            DESTINATION ${JCONFIG_INCLUDE_INSTALL_DIR}
    )
    install(
            FILES ${JCONFIG_CMAKE_PROJECT_CONFIG_FILE} ${JCONFIG_CMAKE_VERSION_CONFIG_FILE}
            DESTINATION ${JCONFIG_CONFIG_INSTALL_DIR}
    )
    export(
            TARGETS ${JCONFIG_TARGET_NAME}
            NAMESPACE ${PROJECT_NAME}::
            FILE ${JCONFIG_CMAKE_PROJECT_TARGETS_FILE}
    )
    install(
            TARGETS ${JCONFIG_TARGET_NAME}
            EXPORT ${JCONFIG_TARGETS_EXPORT_NAME}
            INCLUDES DESTINATION ${JCONFIG_INCLUDE_INSTALL_DIR}
    )
    install(
            EXPORT ${JCONFIG_TARGETS_EXPORT_NAME}
            NAMESPACE ${PROJECT_NAME}::
            DESTINATION ${JCONFIG_CONFIG_INSTALL_DIR}
    )
endif ()
