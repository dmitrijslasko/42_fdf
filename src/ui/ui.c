/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:44 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 21:37:26 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_ui(t_data *data)
{
	if (data->view->lang == DE)
		add_controls_panel_de(data);
	else if (data->view->lang == EN)
		add_controls_panel_en(data);
	add_coor_info(data);
	add_license_info(data);
}
