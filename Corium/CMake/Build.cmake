FILE(GLOB_RECURSE "CORIUM_SOURCES" "Corium/Source/*.cpp"  "Corium/Source/*.hpp")
ADD_LIBRARY("CoriumCompiler" STATIC "${CORIUM_SOURCES}")
TARGET_INCLUDE_DIRECTORIES("CoriumCompiler" PRIVATE "Nominax/Include/")
TARGET_LINK_LIBRARIES("CoriumCompiler" NominaxRuntime)

ADD_EXECUTABLE("Corium" "Corium/Entry/Main.cpp")
TARGET_LINK_LIBRARIES("Corium" CoriumCompiler)
TARGET_INCLUDE_DIRECTORIES("Corium" PRIVATE "Nominax/Include/")

INCLUDE("Corium/CMake/UnitTests.cmake")