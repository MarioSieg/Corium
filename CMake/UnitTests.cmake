IF (${CORIUM_BUILD_UNIT_TESTS})
	ADD_SUBDIRECTORY("Tools/googletest")
	SET("TEST_INCLUDE" "Tools/googletest/googletest/include/gtest/")
ENDIF()
