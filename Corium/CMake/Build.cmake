FILE(GLOB_RECURSE "CORIUM_SOURCES" "Corium/Source/*.cpp"  "Corium/Source/*.hpp")
ADD_EXECUTABLE("Corium" "${CORIUM_SOURCES}")
TARGET_LINK_LIBRARIES("Corium" "Nominax")