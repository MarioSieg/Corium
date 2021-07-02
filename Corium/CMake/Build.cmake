FILE(GLOB_RECURSE "CORIUM_SOURCES" "Corium/Source/*.cpp"  "Corium/Source/*.hpp")
ADD_EXECUTABLE("Corium" "${CORIUM_SOURCES}")

TARGET_INCLUDE_DIRECTORIES("Corium" PRIVATE "Nominax/Include/")
TARGET_LINK_LIBRARIES("Corium" NominaxRuntime)

ADD_SUBDIRECTORY("SharedTools/antlr4")
TARGET_INCLUDE_DIRECTORIES("Corium" PRIVATE "SharedTools/antlr4/runtime/src")
TARGET_LINK_LIBRARIES("Corium" "antlr4_static")
TARGET_COMPILE_OPTIONS("Corium" PRIVATE "-std=c++17")

INCLUDE("Corium/CMake/UnitTests.cmake")