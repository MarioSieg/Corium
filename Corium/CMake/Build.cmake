FILE(GLOB_RECURSE "CORIUM_SOURCES" "Corium/Source/*.cpp"  "Corium/Source/*.hpp")
ADD_EXECUTABLE("CoriumC" "${CORIUM_SOURCES}")

FILE(GLOB_RECURSE "CORIUM_PARSER_SOURCES" "Corium/Parser/*.cpp"  "Corium/Parser/*.h")
ADD_LIBRARY("CoriumParser" STATIC "${CORIUM_PARSER_SOURCES}")
TARGET_COMPILE_OPTIONS("CoriumParser" PRIVATE "-std=c++17")
TARGET_COMPILE_OPTIONS("CoriumParser" PRIVATE "-fexceptions")
TARGET_LINK_LIBRARIES("CoriumC" "CoriumParser")

INCLUDE("Corium/CMake/Extern.cmake")
INCLUDE("Corium/CMake/UnitTests.cmake")