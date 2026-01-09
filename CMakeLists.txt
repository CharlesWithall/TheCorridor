cmake_minimum_required(VERSION 3.21)
project(TheCorridor LANGUAGES CXX)

# vcpkg integration (optional when using a toolchain file externally)
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(VCPKG_ROOT "C:/Users/charl/vcpkg" CACHE PATH "vcpkg root")
    if (EXISTS "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
        set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    endif()
endif()

if (NOT DEFINED VCPKG_TARGET_TRIPLET)
    set(VCPKG_TARGET_TRIPLET "x64-windows" CACHE STRING "vcpkg triplet")
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE THECORRIDOR_SOURCES
     CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/TheCorridor/*.cpp"
     "${CMAKE_SOURCE_DIR}/TheCorridor/*.c"
)

add_executable(TheCorridor ${THECORRIDOR_SOURCES})

find_package(SFML 2.5 CONFIG REQUIRED COMPONENTS system window graphics audio network)

target_link_libraries(TheCorridor PRIVATE sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


add_custom_command(TARGET TheCorridor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Data"
        "${CMAKE_BINARY_DIR}/Data"
)
