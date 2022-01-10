cmake_minimum_required(VERSION 3.0)
project (Corium LANGUAGES C)

if (WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W3 /WX")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
endif()

add_library(libcorium STATIC corium/corium.h corium/corium.c)
target_include_directories(libcorium PRIVATE nominax/)

add_library(libnominax STATIC nominax/nominax.h nominax/nominax.c)

add_executable(corium corium/app.c)
target_link_libraries(corium libcorium)

add_executable(nominax nominax/app.c)
target_link_libraries(nominax libnominax)

add_executable(tests corium/tests.c)
target_link_libraries(tests libcorium)
target_link_libraries(tests libnominax)
target_include_directories(tests PRIVATE nominax/)
