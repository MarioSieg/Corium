ADD_SUBDIRECTORY("SharedTools/fmt/")
TARGET_LINK_LIBRARIES("NominaxRuntime" "fmt")
TARGET_LINK_LIBRARIES("NominaxRuntimeAnaly" "fmt")
TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "fmt")

IF (NOT WIN32)
	TARGET_LINK_LIBRARIES("NominaxRuntime" "dl")
    TARGET_LINK_LIBRARIES("NominaxRuntime" "pthread")

    TARGET_LINK_LIBRARIES("NominaxRuntimeAnaly" "dl")
    TARGET_LINK_LIBRARIES("NominaxRuntimeAnaly" "pthread")

    TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "dl")
    TARGET_LINK_LIBRARIES("NominaxRuntimeTest" "pthread")
ENDIF()
