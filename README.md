# FDF, a wireframe model (School 42 project)
The FDF (Fil de Fer) project at 42 is a graphics programming task where you create a program in C to display a 3D wireframe map from a set of 2D coordinates.  
The input is a file containing a grid of elevation points, and the program visualizes the map using isometric projection.

**Key features of the project include:**
* Parsing the map file: Read and interpret a grid of elevation values from a text file.
* Rendering: Convert the 2D grid data into a 3D representation with lines connecting the points to form a mesh.
* Isometric projection: Display the 3D map in a 2D isometric perspective to provide depth and structure.
* Controls: Implement interactivity for zooming, rotating, and translating the view, allowing dynamic exploration of the map.
* Graphics library: Typically, the project uses the MiniLibX library to handle window management and drawing.
The project emphasizes skills in graphics programming, data manipulation, and mastering low-level rendering concepts.

---

## Score:
✅ 125/125 (with bonus)

![42.fdf map](./_img/fdf-header-image-min.png)

---

## Installation and launch 🚀
**1. Clone the repo:**
```bash
git clone https://github.com/dmitrijslasko/fdf42.git
```
**2. Go into the folder:**
```bash
cd fdf42
```
**3. Build the program:**
```bash
make
```
**4. Launch the program with the selected map:**
```bash
./fdf ./maps/42.fdf
```
Other maps are stored in the ./maps/ folder.

---

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

---

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

---

## Known issues 🚨
1. macOS not working out of the box (the project was written on Linux Ubuntu)
1. Lack of z-buffer – resulting in line overlay problems (best seen on big maps like ./maps/t1.fdf)
1. Due to the limitation of the MLX library, the control panel text is output to the window, not the image.
This sometimes results in blinking (because of the constant rerendering).
However, it perfectly shows why we should use the image pre-render for the main part of the program.  
It's best to reimplement this functionality with an XPM image

---

## Reading list 📚
1. Getting started with the minilibx
https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

---

## Inspirations 💡
1. Awesome project with implemented spherical projection
https://github.com/ailopez-o/42Barcelona-FdF
2. A simple project that works on MacOS (was a great starting point for me, helping to implement mouse rotations)
https://github.com/VBrazhnik/FdF
3. This article mentions using an XPM image for the control panel
https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc

## Questions? 🤔
**Feel free to contact me:**
**Slack:** @dmlasko  
**E-mail**: dmitrijs.lasko@gmail.com  
**Telegram:** @lalamoose  
