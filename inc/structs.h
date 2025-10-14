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
	EN,
	DE
}	t_lang;

typedef enum e_projection
{
	ISO,
	PARALLEL
}	t_projection;

// structures
typedef struct s_coor
{
	int		x;
	int		y;
	int		z;
	int		z_clr;
	double	z_rel;
	int		z_clr_custom;
	int		x_iso;
	int		y_iso;
	float		z_depth;
}	t_coor;

typedef struct s_map
{
	t_coor	**coor;
	int		width;
	int		height;
	double	z_max;
	int		z_min;
	int		has_clr_info;
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
	int		show_welcome;
	int		show_admin;
	int		lang;
	int		show_nodes;
	int		node_size;
	int		use_custom_clrs;
	int		lo_clr;
	int		hi_clr;
	int		bg_clr;
	double	xy_dist;
	double	z_dist;
	double	z_limit;
	int		x_off;
	int		y_off;
	double	zoom;
	int		projection;
	double	rot_x;
	double	rot_y;
	double	rot_z;
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	double	c_x;
	double	c_y;
	double	origin_x;
	double	origin_y;
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

typedef struct s_node
{
	int	x;
	int	y;
	int	z;
	int	clr;
}	t_node;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_map	*map;
	
	float	**z_buffer;

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
	int	clr;
}	t_line;

#endif
