IF (${CORIUM_BUILD_UNIT_TESTS})
	ADD_SUBDIRECTORY("SharedTools/googletest")
	SET("TEST_INCLUDE" "SharedTools/googletest/googletest/include/gtest/")
ENDIF()
