/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:44:01 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:19 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

static void	ft_print(char *s, t_flags *f, int output_len)
{
	if (f->align_left) 
	{
		ft_putsubstr(s, output_len);
		while (f->space_len-- > 0)
			ft_putchar(' ');
	}
	else 
	{
		while (f->space_len-- > 0)
			ft_putchar(' ');
		ft_putsubstr(s, output_len);
	}
}

void	ft_putstr_new(char *s, t_flags *f, size_t *counter)
{
	int	output_len;

	if (s == NULL && f->prcsn && f->prcsn_len < 6)
		s = "";
	else if (s == NULL)
		s = "(null)";
	output_len = ft_strlen(s);
	if (f->prcsn && f->prcsn_len < output_len)
		output_len = f->prcsn_len;
	f->space_len = f->min_width - output_len;
	if (f->space_len > 0)
		*counter += f->space_len;
	*counter += output_len;
	ft_print(s, f, output_len);
}
