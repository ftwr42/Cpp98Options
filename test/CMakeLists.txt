#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

include(GoogleTest)

add_executable(cpp98opts_tests checkoptions.cpp
        ../src/cpp98opts.cpp ../src/include/cpp98opts/cpp98opts.h
        ../src/option.cpp ../src/include/cpp98opts/option.h
        ../src/chapter.cpp ../src/include/cpp98opts/chapter.h
        ../src/optsType.cpp ../src/include/cpp98opts/optsType.h
)

target_link_libraries(
        cpp98opts_tests
        PRIVATE
        cpp98opts_options
        GTest::gtest
        GTest::gtest_main

)

gtest_discover_tests(cpp98opts_tests)
