# HOW TO COMPILE CPP CODE FOR BOTH MSVC AND G++

## GNU CPP COMPILER
 - Download MinGW64
 - Install
 - Set Up Environment Variable for g++
 - Use the following command for compiling:
  `g++ [c file name with extendsion] -o [exe file name]`
  - To run it simply type:
  `[exe file name]`

  * Example:
  `g++ main.c -o main && main`


## MSVC COMPILER
 - Download MSVC 2022 Redistribution
 - Install
 - Open a "Developer Command Prompt"
 - Use `cl \EHsc [c filename]`

 * Example:
 `cl \EHsc main.c && main`