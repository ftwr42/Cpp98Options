cmake_minimum_required(VERSION 3.26)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")

project(Cpp98Options CXX)
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${PROJECT_SOURCE_DIR}/project_options.cmake)
include(${PROJECT_SOURCE_DIR}/dependencies.cmake)

cpp98opts_setup_dependencies()

add_subdirectory(src bin)

if (${cpp98opts_build_tests})
    enable_testing()
    add_subdirectory(test)
endif ()

install(TARGETS cpp98opts EXPORT cpp98opts-targets ARCHIVE
        FILE_SET HEADERS
)
install(EXPORT cpp98opts-targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cpp98opts/cmake
        NAMESPACE cpp98opts::
)
install(FILES "cpp98opts-config.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cpp98opts/cmake
)

find_package(boost_atomic REQUIRED CONFIG)
find_package(boost_smart_ptr REQUIRED CONFIG)
find_package(boost_optional REQUIRED CONFIG)
find_package(boost_algorithm CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(boost_lexical_cast CONFIG REQUIRED)
find_package(boost_format CONFIG REQUIRED)


target_link_libraries(cpp98opts PUBLIC
        Boost::atomic
        fmt::fmt
        Boost::optional
        Boost::lexical_cast
        Boost::format
        Boost::smart_ptr
        Boost::algorithm)
target_link_libraries(cpp98opts_tests PUBLIC
        Boost::atomic
        fmt::fmt
        Boost::optional
        Boost::lexical_cast
        Boost::format
        Boost::smart_ptr
        Boost::algorithm)

