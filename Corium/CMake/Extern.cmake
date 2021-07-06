ADD_SUBDIRECTORY("Corium/Extern/antlr4")
TARGET_COMPILE_OPTIONS("antlr4_static" PUBLIC "-std=c++17")
TARGET_INCLUDE_DIRECTORIES("CoriumParser" PRIVATE "Corium/Extern/antlr4/runtime/src")
TARGET_LINK_LIBRARIES("CoriumParser" "antlr4_static")