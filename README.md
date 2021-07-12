An in progress personal project written entirely in C++. Currently only supports sphere objects. Matte, metalic, and translucent material. 



To build and run use:

`make`

`make run`

These commands must be run from a linux environment with make or using the WLS.

At the moment the rendering parameters are controlled from a **constants.h** file and the scene objects are configured in **driver.cpp**. 
Very soon I should be converting the rendering paramters to command line arguments and the scene configuration to json input.

![alt text](output/medium_quality_color.bmp?raw=true)

![alt text](output/reflection_no_fuzz.bmp?raw=true)

![alt text](output/firstColor.bmp?raw=true)


![alt text](output/blur_1.bmp?raw=true)

