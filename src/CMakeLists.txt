add_subdirectory(frontend)
add_subdirectory(ir)
add_subdirectory(jitter)

add_executable(jry main.cpp)
target_link_libraries(jry jittery_frontend jittery_jit ${ANTLR4} ${LIBJIT})