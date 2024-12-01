/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:44:34 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:11 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

void	ft_putchar_new(char c, t_flags *f, size_t *counter)
{
	int	spaces_len;
	int	i;

	spaces_len = 0;
	if (f->align_left)
		ft_putchar_fd(c, 1);
	if (f->min_width != 0)
		spaces_len = f->min_width - 1;
	i = spaces_len;
	while (i--)
		ft_putchar_fd(f->fill_char, 1);
	if (!f->align_left)
		ft_putchar_fd(c, 1);
	*counter += 1 + spaces_len;
}
