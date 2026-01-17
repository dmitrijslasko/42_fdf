/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:44:50 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 11:26:43 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// enum
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_lang
{
	ENGLISH,
	DEUTSCH
}	t_lang;

typedef enum e_projection_type
{
	ISOMETRIC,
	PARALLEL
}	t_projection_type;

// structures
typedef struct t_node
{
	// from parsing
	int		x;
	int		y;
	int		z;

	int		z_color;
	double	z_rel;
	int		z_clr_custom;
	
	// screen space
	int		x_iso;
	int		y_iso;
	float	z_depth;
}	t_node;

typedef struct s_map
{
	t_node	**nodes;
	int		width;
	int		height;
	double	z_max;
	int		z_min;
	int		has_color_info;
}	t_map;

typedef struct s_mouse
{
	char	lmb_is_pressed;
	char	rmb_is_pressed;
	int		x;
	int		y;
	int		previous_x;
	int		previous_y;
}	t_mouse;

typedef struct s_view
{
	int		show_welcome_img;
	int		show_admin;
	int		ui_language;

	int		show_lines;

	int		show_nodes;
	int		node_size;

	int		bg_clr;
	int		lo_clr;
	int		hi_clr;
	int		use_custom_colors;

	double	xy_dist;
	double	z_dist;
	double	z_limit;
	int		x_off;
	int		y_off;
	double	zoom;
	double	zoom_animation;
	int		projection_type;

	double	rot_x;
	double	rot_y;
	double	rot_z;

	int		bounding_box_min_x;
	int		bounding_box_max_x;
	int		bounding_box_min_y;
	int		bounding_box_max_y;
	double	bounding_box_center_x;
	double	bounding_box_center_y;
	double	origin_x_iso;
	double	origin_y_iso;

	int		auto_rotate;
	int		auto_rotate_axis;
	int		auto_rotate_zoom_dir;
	int		show_controls;
}	t_view;

typedef struct s_rgb
{
	int	rgb;
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_map	*map;
	// t_map	*map2;
	
	float	**z_buffer_map;

	t_view	*view;
	t_mouse	*mouse;
	void	*welcome_img;
}	t_data;

typedef struct s_line
{
	int	y1;
	int	y2;
	int	x1;
	int	x2;
	int	color;
}	t_line;

#endif
