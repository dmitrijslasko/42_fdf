#ifndef FDF_H
# define FDF_H

// includes
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>

// headers
# include "colors.h"
# include "settings.h"
# include "structs.h"
# include "keys.h"
# include "errors.h"
# include "mouse.h"

// user libraries
# include "../lib/libft/libft.h"
# include "../lib/printf/inc/ft_printf.h"
# include "../lib/get_next_line/get_next_line_bonus.h"

// functions
// keypresses
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);

// parsing maps
t_map	*parse_map(t_data *data, char* filepath);
t_map	*init_map(t_data *data, int width, int height, int z);
void	fill_in_map(t_data *data, char *filepath);
void    print_map(t_map *map);
void    print_map_coors(t_map *map);

// clrs
unsigned int	pack_rgb(int red, int green, int blue);
int		get_clr_bween_clrs(double distance, int start_clr, int end_clr);
int		hex_to_int(const char *hexString);

// drawing
void	img_pix_put(t_img *img, int x, int y, int clr);
int		pixel_is_in_window(int x, int y);

void	draw_node(t_data *data, int x, int y, int clr);
int		draw_map(t_data *data);
void	get_iso_coor(int *x, int *y, int *z, t_view *view);
void	update_iso_coors(t_data *data, t_map *map, t_view *view);


void	update_z_rel(t_data *data);

// drawing lines
void	draw_vert_line(t_data *data, t_coor point_1, t_coor point_2);
void	draw_vert_line2(t_img *img, int x, int y1, int y2, int clr, int clr2);
void	draw_single_clr_line(t_img *img, t_line line);
void	draw_sloped_line(t_data *data, t_coor point_1, t_coor point_2);
void	draw_hor_line(t_img *img, t_line line);
void	connect_two_nodes(t_data *data, t_coor *coor_1, t_coor *coor_2);
int     draw_rectangle(t_img *img, t_coor *point_1, t_coor *point_2, int clr);

// aux
void	swap(void *a, void *b, size_t size);

// memory management
void    free_map(t_map *map, int allocated_rows);
void	free_data(t_data *data);
void    *gc_malloc(t_list **pointers, int size, char *desc);

void	update_bounding_box(t_data *data);

void    init_view(t_view *view);
void    setup_view(t_data *data);

void	show_admin(t_data *data);
void	draw_axis(t_data *data);

t_coor	update_origin_coor(t_data *data);

void	add_ui(t_data *data);

double		deg_to_radians(double angle);

void	reset_angle(t_data *data);

int close_window(void);

int			mouse_move(int x, int y, t_data *data);
int			mouse_release(int button, int x, int y, t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);

int	render(t_data *data);

int	check_arguments(int argc, char **argv);

void reset_angle_degrees(double *angle);
void reset_all_angle_degrees_data(t_data *data);

int		get_clr_bween_points(t_data *data, t_coor point_1, t_coor point_2, double distance);

void gc_free_all(t_list **pointers);
void	reset_bounding_box(t_data *data);

int	update_colors(t_data *data, t_map *map);

void	*protected_malloc(size_t size);

#endif
