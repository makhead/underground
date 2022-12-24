cmake_minimum_required(VERSION 3.12)
project(MyProject VERSION 1.0.0)
#source files
file(GLOB SOURCES "src/*.c")
add_executable(main ${SOURCES})
#libs
add_library(
    libgraphics
    libgraphics/exceptio
    libgraphics/genlib
    libgraphics/graphics
    libgraphics/random
    libgraphics/simpio
    libgraphics/strlib
)
include_directories(libgraphics include)
target_link_libraries(main libgraphics)