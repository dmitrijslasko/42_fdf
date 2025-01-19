# FdF, a wire frame model (School 42 project)
The goal of the project is to transform 2D maps, passed as an array, into 3D maps.

## Score:
✅ 125/125

## About

## Installation and launch
1) Build the program by running 'make' or 'make all'.
2) Launch the program: ./fdf ./maps/42
Other maps are stored in the ./maps/ folder.

## Implemented functionality
![fdf-demo](https://github.com/dmitrijslasko/42-assets/blob/d9ae0a69c1fc9aea10fa920e7ee1ba405123e805/fdf/dmlasko-fdf-demo-v2.gif?raw=true)
1) Welcome screen (not allowed by the project's subject, but using it via a workaround in the Makefile)
2) Mouse & keyboard rotation and zoom
3) Map height & color information parser
4) Height scaling
5) Relative height color output (with easily customizable color schemes)
6) Control panel language switch (English, German)
7) 2 projections: Isometric / parallel
8) Rotation angle information panel
9) Special visual admin mode

## Known issues
1) macOS not working out of the box (was written on Linux Ubuntu)
2) Lack of z-buffer – resulting in line overlay problems
3) Due to the limitation of the MLX library, the control panel text is output to the window, not the image.
This sometimes results in blinking (because of the constant rerendering).
However, it perfectly shows why we should use the image pre-render for the main part of the program.