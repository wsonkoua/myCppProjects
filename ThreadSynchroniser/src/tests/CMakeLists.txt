set (thread_synchroniser_TEST_SOURCE
"thread_synchroniser.cpp")


add_executable(thread_synchroniser_test ${thread_synchroniser_TEST_SOURCE})
target_include_directories(thread_synchroniser_test PRIVATE "${PROJECT_SOURCE_DIR}/src/tests")

target_link_libraries(thread_synchroniser_test PRIVATE thread_synchroniser_lib gtest_main)
target_compile_definitions (thread_synchroniser_test PRIVATE ${thread_synchroniser_DEFINITIONS})


add_test(NAME thread_synchroniser_unit_test
	COMMAND thread_synchroniser_test)