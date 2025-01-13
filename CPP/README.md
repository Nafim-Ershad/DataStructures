# HOW TO COMPILE CPP CODE FOR BOTH MSVC AND G++

## GNU CPP COMPILER
 - Download MinGW64
 - Install
 - Set Up Environment Variable for g++
 - Use the following command for compiling:
  `g++ [cpp file name with extendsion] -o [exe file name]`
  - To run it simply type:
  `[exe file name]`

  * Example:
  `g++ main.cpp -o main && main`


## MSVC COMPILER
 - Download MSVC 2022 Redistribution
 - Install
 - Open a "Developer Command Prompt"
 - Use `cl \EHsc [cpp filename]`

 * Example:
 `cl \EHsc main.cpp && main`