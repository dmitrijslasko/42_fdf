/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_clrs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:39 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 10:58:07 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_switch_clrs(int key, t_data *data)
{
	if (key == XK_1)
	{
		data->view->use_custom_clrs = 0;
		data->view->bg_clr = DEF_BG_COLOR;
	}
	if (key == XK_2)
	{
		data->view->use_custom_clrs = 1;
		data->view->lo_clr = SCHEME_1_LO;
		data->view->hi_clr = SCHEME_1_HI;
		data->view->bg_clr = SCHEME_1_BG;
		update_colors(data, data->map);
	}
	if (key == XK_3)
	{
		data->view->use_custom_clrs = 1;
		data->view->lo_clr = SCHEME_2_LO;
		data->view->hi_clr = SCHEME_2_HI;
		data->view->bg_clr = SCHEME_2_BG;
		update_colors(data, data->map);
	}
	return (0);
}
