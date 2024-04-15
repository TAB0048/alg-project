# TURISTIKA alias HEIGHT MAP SOLVER

This project implements a tool for finding the shortest path in a height map. It reads data from an input file and searches for the shortest path from starting point to ending point using Breadth-First Search (BFS) algorithm.
Result of the search is then displayed in the console as a sequence of steps with x, y coordinates and height for each step, length of the path included. 

## Requirements

To build and run this project, you need:

- CMake
- C++ compiler
- Doxygen

## Build Instructions

To build this project, navigate to the project directory and execuse these commands: 

`mkdir build`
`cd build`
`cmake ..`
`make`
`./height_map`

## Documentation

To generate documentation using Doxygen, follow these steps:

1. Make sure Doxygen is installed on your system.
2. In the project directory, run: `doxygen Doxyfile`.
3. Open the generated HTML documentation located in the `doc` directory.
