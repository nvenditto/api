cmake_minimum_required(VERSION 3.15)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/nvenditto/hunter/archive/v0.23.295.tar.gz"
    SHA1 "A9A29F9D9EEFE5F106295610D8CCFF3028DA7ECC"
)

project(api VERSION 1.0.0 LANGUAGES CXX)

hunter_add_package(basic)
find_package(basic CONFIG REQUIRED)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES CONFIGURE_DEPENDS "include/api/*.h")

add_library(api STATIC ${SOURCES})

target_include_directories(api PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  	$<INSTALL_INTERFACE:include>
)

target_compile_features(api INTERFACE cxx_std_14)

target_link_libraries(api PUBLIC basic::basic)


set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include/${PROJECT_NAME}")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(
    TARGETS api
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

install(
    FILES ${INCLUDE_FILES}
    DESTINATION "${include_install_dir}"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)