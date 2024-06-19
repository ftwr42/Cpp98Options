add_library(cpp98opts)

target_sources(cpp98opts
        PRIVATE
        cpp98opts.cpp
        option.cpp

        PUBLIC FILE_SET HEADERS
        BASE_DIRS include FILES
        include/cpp98opts/cpp98opts.h
        include/cpp98opts/option.h
)

target_include_directories(
        cpp98opts
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)


