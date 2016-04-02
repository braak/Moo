set(MOO_LIB_SRCS Moo.cpp Version.cpp)
add_library(moo ${MOO_LIB_SRCS})

add_executable(moo_binary  main.cpp)
set_target_properties(moo_binary PROPERTIES OUTPUT_NAME moo)
target_link_libraries(moo_binary moo)
