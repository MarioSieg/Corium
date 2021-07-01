FILE(GLOB_RECURSE "CORIUM_SOURCES" "Corium/Source/*.cpp"  "Corium/Source/*.hpp")
ADD_EXECUTABLE("Corium" "${CORIUM_SOURCES}")
TARGET_INCLUDE_DIRECTORIES("Corium" PRIVATE "Nominax/Include/")
TARGET_LINK_LIBRARIES("Corium" NominaxRuntime)

INCLUDE("Corium/CMake/UnitTests.cmake")