INCLUDE("Corium/Extern/antlr4/cmake/ExternalAntlr4Cpp.cmake")
TARGET_INCLUDE_DIRECTORIES("CoriumParser" PRIVATE "Corium/Extern/antlr4/runtime/src")
TARGET_INCLUDE_DIRECTORIES("CoriumC" PRIVATE "Corium/Extern/antlr4/runtime/src")
TARGET_LINK_LIBRARIES("CoriumParser" "antlr4_static")
