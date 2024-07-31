add_library(cpp98opts)

target_sources(cpp98opts
        PRIVATE
        cpp98opts.cpp include/cpp98opts/cpp98opts.h
        chapter.cpp include/cpp98opts/chapter.h
        option.cpp include/cpp98opts/option.h
        optsType.cpp include/cpp98opts/optsType.h
)

target_include_directories(
        cpp98opts
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
