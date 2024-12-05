# _Dimmer project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

## Commands
To build application:
``` 
idf.py build
```
To Flash and Monitor:
```
idf.py -p COMx flash monitor
```

## Project folder contents

The project **dimmer_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 
Library is included in header file [main](main/RBDdimmer.h) and C file for library is at [main](main/RBDmcuESP32.c).  

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   ├── main.c
│   ├── RBDdimmer.h
│   ├── RBDmcuESP32.c
└── README.md                  This is the file you are currently reading
```

## Project Aim

So this library is from RBDimmer library ported from Arduino Framework to the ESP-IDF framework.
For now,
1. I can control the brightness of LED and output load.
2. I can take the brightness to the full level at 99 with Max brightness.

But what I am missing is,
1. I cannot turn the load completely off.
2. I cannot make it totally zero
3. At the output there still remains some voltages like around 10VAC even when I have set the power to 1 or 0 in code.
4. Below brightness or power level 50, the load flickers. 
