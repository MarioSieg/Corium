IF ("${IS_CLANG_CL}")
	SET("NO_RTTI" "-Xclang -fno-rtti")
ELSE()
	SET("NO_RTTI" "-fno-rtti")
ENDIF()

TARGET_COMPILE_OPTIONS("NominaxRuntime" PRIVATE "${NO_RTTI}")
TARGET_COMPILE_OPTIONS("NominaxRuntimeAnaly" PRIVATE "${NO_RTTI}")
