cmake_minimum_required(VERSION 3.28)
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
        NAMESPACE c2k::
)
install(FILES "cpp98opts-config.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cpp98opts/cmake
)
