IF (${CORIUM_BUILD_UNIT_TESTS})
	FILE(GLOB_RECURSE "NOMINAX_TEST_SOURCES" "Nominax/Tests/*.cpp")
	ADD_EXECUTABLE("NominaxUnitTest" "${NOMINAX_TEST_SOURCES}")
	TARGET_COMPILE_OPTIONS("NominaxUnitTest" PRIVATE "-frtti")
	ADD_TEST(NAME "NominaxUnitTest" COMMAND "NominaxUnitTests")
	TARGET_INCLUDE_DIRECTORIES("NominaxUnitTest" PUBLIC "${TEST_INCLUDE}")
	TARGET_LINK_LIBRARIES("NominaxUnitTest" "gtest")
	TARGET_LINK_LIBRARIES("NominaxUnitTest" "NominaxRuntimeTest")
	ADD_COMPILE_DEFINITIONS("NOMINAX_TESTING")

	# with GCC we need to link posix threads
	IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        TARGET_LINK_LIBRARIES("NominaxUnitTest" "pthread")
    ENDIF()

	CONFIGURE_FILE("Nominax/Tests/MockInput.txt" "${CMAKE_CURRENT_BINARY_DIR}/MockInput.txt" COPYONLY)
ENDIF()