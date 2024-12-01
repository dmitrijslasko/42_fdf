/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:02:56 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:37:31 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

#define SPECIFIERS "cspdiuxX%"

void	ft_init_flags(t_flags *f)
{
	f->align_left = 0;
	f->di_precdng_sp = 0;
	f->di_precdng_pl = 0;
	f->x_preceding_symbols = 0;
	f->min_width = 0;
	f->prcsn = 0;
	f->prcsn_len = 0;
	f->fill_char = ' ';
	f->preceding_0_len = 0;
	f->space_len = 0;
	f->is_neg = 0;
	f->base = "";
}

void	ft_get_width_and_prcsn_len(const char *s, t_flags *f)
{
	if (ft_isdigit(*s) && !ft_strchr(SPECIFIERS, *s) && !f->prcsn)
	{
		f->min_width *= 10;
		f->min_width += *s - '0';
	}
	if (ft_isdigit(*s) && !ft_strchr(SPECIFIERS, *s) && f->prcsn)
	{
		f->prcsn_len *= 10;
		f->prcsn_len += *s - '0';
	}
}

size_t	ft_parse_f(const char *s, t_flags *f)
{
	const char	*start_ptr;

	start_ptr = s;
	while (ft_strchr(SPECIFIERS, *s) == NULL)
	{
		if (*s == '+')
			f->di_precdng_pl = 1;
		if (*s == ' ' && f->di_precdng_pl == 0)
			f->di_precdng_sp = 1;
		if (*s == '#')
			f->x_preceding_symbols = 1;
		if (*s == '-')
			f->align_left = 1;
		if (*s == '.')
		{
			f->prcsn = 1;
			f->fill_char = ' ';
		}
		if (*s == '0' && f->prcsn == 0 && !ft_isdigit(*(s - 1)))
			f->fill_char = '0';
		ft_get_width_and_prcsn_len(s, f);
		s++;
	}
	return (s - start_ptr);
}
