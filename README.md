# build-cmake
This repository is dedicated to store a simple cmake architecture files, reusable for other projects 
It contains a sandbox project, that contains simple C++ files meant to print Hello World. 
The point of such CMake structure is to: 
- Enable simple compilation of C++ projects ;
- Easy unit-testing based on Boost.

##Required

 - GCC or any C++ compiler
 - Boost (version 1.62 or higher)
 - CMake (version 2.8 or higher) + ccmake tool for convenience

##Compile

Create bin folder at the root of the project, and run cmake to generate the Makefiles. 
Run make and make test-all, to compile the C++ code. 


