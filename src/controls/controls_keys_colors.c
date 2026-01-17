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

int	keypress_switch_clrs(int key, t_data *dt)
{
	if (key == XK_1)
	{
		dt->view->use_custom_colors = 0;
		dt->view->bg_clr = DEF_BG_COLOR;
	}
	if (key == XK_2)
	{
		dt->view->use_custom_colors = 1;
		dt->view->lo_clr = SCHEME_0_LO;
		dt->view->hi_clr = SCHEME_0_HI;
		dt->view->bg_clr = SCHEME_0_BG;
		update_colors(dt, dt->map);
	}
	if (key == XK_3)
	{
		dt->view->use_custom_colors = 1;
		dt->view->lo_clr = SCHEME_1_LO;
		dt->view->hi_clr = SCHEME_1_HI;
		dt->view->bg_clr = SCHEME_1_BG;
		update_colors(dt, dt->map);
	}
	if (key == XK_4)
	{
		dt->view->use_custom_colors = 1;
		dt->view->lo_clr = SCHEME_2_LO;
		dt->view->hi_clr = SCHEME_2_HI;
		dt->view->bg_clr = SCHEME_2_BG;
		update_colors(dt, dt->map);
	}
	if (key == XK_5)
	{
		dt->view->use_custom_colors = 1;
		dt->view->lo_clr = SCHEME_3_LO;
		dt->view->hi_clr = SCHEME_3_HI;
		dt->view->bg_clr = SCHEME_3_BG;
		update_colors(dt, dt->map);
	}
	return (0);
}
