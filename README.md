# FDF, a wireframe model (School 42 project)
The first visual graphic project in school 42.
The goal of the project is to transform 2D maps, passed as an array, into 3D maps.

## Score:
✅ 125/125 (with bonus)

## Installation and launch 🚀
1. Clone the repo: 
```bash
git clone https://github.com/dmitrijslasko/fdf42.git
```
2. Go into the folder:
```bash
cd fdf42
```
3. Build the program:
```bash
make
```
4. Launch the program: 
```bash
./fdf ./maps/42
```
Other maps are stored in the ./maps/ folder.

## Implemented functionality 🤖
![fdf-demo](https://github.com/dmitrijslasko/42-assets/blob/d9ae0a69c1fc9aea10fa920e7ee1ba405123e805/fdf/dmlasko-fdf-demo-v2.gif?raw=true)
1. Welcome screen (not allowed by the project's subject, but using it via a workaround in the Makefile)
1. Mouse / keyboard rotation and zoom
1. Map height & color information parser
1. Height scaling
1. Relative height color output (with easily customizable color schemes)
1. Control panel overlay
1. Control panel language switch (English, German)
1. 2 projections: Isometric / parallel
1. Rotation angle information panel
1. Special visual admin mode
1. Show / hide nodes (not shown in the GIF above)

## Controls 🕹️
* Zoom: Scroll or [+] / [-]
* Move: Hold left mouse button or Arrows
* Flatten / raise height: [\[] / [\]]
* Rotate: Hold right mouse button & Move
* X-Axis - [Q] / [W]
* Y-Axis - [A] / [S]
* Z-Axis - [Z] / [W]
* Switch projections: ISO: [I], Parallel: [P]
* Show / hide nodes: [N]
* Reset view: [R]
* Map colors: [1][2][3]
* Secret admin mode: [/]

## Known issues 🚨
1. macOS not working out of the box (the project was written on Linux Ubuntu)
1. Lack of z-buffer – resulting in line overlay problems (best seen on big maps like ./maps/t1.fdf)
1. Due to the limitation of the MLX library, the control panel text is output to the window, not the image.
This sometimes results in blinking (because of the constant rerendering).
However, it perfectly shows why we should use the image pre-render for the main part of the program.  
It's best to reimplement this functionality with using an XPM image

## Reading list

## Inspirations
1. Awesome project with spherical projection
https://github.com/ailopez-o/42Barcelona-FdF
2. A simple project that works on MacOS (was a great starting point for me, helping to implement mouse rotations)
https://github.com/VBrazhnik/FdF
3. This article mentions using an XPM image for the control panel
https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc

## Questions? ❓
Feel free to contact me:  
Slack: @dmlasko  
E-mail: dmitrijs.lasko@gmail.com  
Telegram: @lalamoose  