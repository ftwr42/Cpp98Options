include(GoogleTest)

function(add_test_executable target)
    # the target name must match the filename of the source file
    add_executable(${target}
            ${target}.cpp
    )

    target_link_libraries(${target} PRIVATE cpp98opts)
    target_link_system_libraries(${target} PRIVATE GTest::gtest GTest::gtest_main)
    gtest_discover_tests(${target})
endfunction()

add_test_executable(check_options)

#target_link_libraries(cpp98opts_tests PRIVATE cpp98opts)
#target_link_system_libraries(cpp98opts_tests PRIVATE GTest::gtest GTest::gtest_main)
#gtest_discover_tests(cpp98opts_tests)
