#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

include(GoogleTest)

#function(add_test_executable target)
#    # the target name must match the filename of the source file
#    add_executable(${target}
#            ${target}.cpp
#            ../src/common.h
#            ../src/cpp98opts.cpp
#            ../src/option.cpp
#    )
#
#    target_link_libraries(${target} PRIVATE cpp98opts)
#    target_link_system_libraries(${target}
#            PRIVATE
#            GTest::gtest
#            GTest::gtest_main
#            cpp98opts_options
#    )
#    gtest_discover_tests(${target})
#endfunction()
#
#add_test_executable(check_options)
#
#target_link_libraries(cpp98opts_tests PRIVATE cpp98opts)
#target_link_system_libraries(cpp98opts_tests PRIVATE GTest::gtest GTest::gtest_main)
#gtest_discover_tests(cpp98opts_tests)

add_executable(cpp98opts_tests checkoptions.cpp
        ../src/cpp98opts.cpp
        ../src/option.cpp
        ../src/chapter.cpp
        ../src/include/cpp98opts/cpp98opts.h
        ../src/include/cpp98opts/option.h
        ../src/include/cpp98opts/chapter.h
)

target_link_libraries(
        cpp98opts_tests
        PRIVATE
        cpp98opts_options
        GTest::gtest
        GTest::gtest_main

)

gtest_discover_tests(cpp98opts_tests)