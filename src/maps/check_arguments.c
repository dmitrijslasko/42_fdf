/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:08 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 20:24:50 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_arguments(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		perror("No map provided... Please provide a map in .fdf format.");
		return (-1);
	}
	else if (argc != 2)
	{
		perror("Too many arguments... Please provide a map in .fdf format.");
		return (-1);
	}
	return (0);
}
