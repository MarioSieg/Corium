ADD_SUBDIRECTORY("Tools/fmt/")
IF(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    TARGET_COMPILE_OPTIONS("fmt" PRIVATE "-fPIC")
ENDIF()
TARGET_LINK_LIBRARIES("NominaxRuntime" "fmt")
IF (${NOMINAX_BUILD_UNIT_TESTS})
    TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "fmt")
ENDIF()

IF (NOT WIN32)
	TARGET_LINK_LIBRARIES("NominaxRuntime" "dl")
    TARGET_LINK_LIBRARIES("NominaxRuntime" "pthread")
    TARGET_LINK_LIBRARIES("NominaxRuntime" "tbb")

    IF (${NOMINAX_BUILD_UNIT_TESTS})
        TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "dl")
        TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "pthread")
        TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "tbb")
    ENDIF()
ENDIF()
