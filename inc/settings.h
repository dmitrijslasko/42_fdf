/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:16:09 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/19 13:52:39 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

// window name
# define WINDOW_NAME         "fdf - dmlasko @ 42Berlin"
# define VERSION_INFO        "fdf project - 42 Berlin - dmlasko, v1.0"

// window size
# define WINDOW_W 	1200
# define WINDOW_H 	900

// default scale
# define X_CENTER 	600
# define Y_CENTER 	450
# define XY_DIST    100
# define Z_DIST 	1

// offsets
# define DEF_OFFSET_X       	0
# define DEF_OFFSET_Y       	0

// colors
# define DEF_BG_COLOR		BLACK

// lines and nodes
# define DRAW_LINES			TRUE
# define DRAW_HORIZONTAL_LINES			TRUE
# define DRAW_VERTICAL_LINES			TRUE
# define DEF_LINE_COLOR     	WHITE
# define DRAW_NODES      	FALSE
# define NODE_SIZE			6

// default rotation (degrees)
# define DEF_ISO_ROT_X		0
# define DEF_ISO_ROT_Y		0
# define DEF_ISO_ROT_Z       0
# define DEF_ISO_ANGLE   	30

# define DEF_PROJECTION  	ISO
# define DEF_ROTATE_STEP 	1
# define DEF_KEY_OFFSET 		10
# define DEF_Z_STEP 			0.5
# define DEF_DRAG_LIM 		400

// zoom settings
# define MAX_ZOOM			5
# define MIN_ZOOM			0.5f
# define KEYBOARD_ZOOM		0.1f
# define DEF_STARTING_ZOOM   0.5f

// mouse sensitivity
# define MOUSE_SENS_ROTATE 	0.2f
# define MOUSE_SENS_DRAG	0.7f
# define MOUSE_SENS_SCROLL 	0.1f

// menu & UI
# define DEF_MENU_ROW_H 	15
# define MENU_WIDTH_PX      200
# define UI_CLR_1    	    WHITE
# define UI_CLR_2    	    GOLD

// bounding box
# define BBOX_COLOR			GREEN
# define CENTER_LINE_PX     50
# define CL_MARGIN          20

// map parsing
# define PARSE_MAP			TRUE
# define TEST_MAP_X			10
# define TEST_MAP_Y		    10
# define TEST_MAP_Z         0

// welcome screen
# define WELCOME_IMAGE       "./assets/images/intro.xpm"
# define SHOW_WELCOME_IMAGE  1

#endif
