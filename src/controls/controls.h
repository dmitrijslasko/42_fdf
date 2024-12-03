/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:29 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 10:41:46 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_set_offs(int key, t_data *data);
int	keypress_reset_offs(int key, t_data *data);

int	keypress_zoom(int key, t_data *data);
int	keypress_Z_DIST(int key, t_data *data);

int	keypress_switch_clrs(int key, t_data *data);

int	keypress_rotation(int key, t_data *data);
