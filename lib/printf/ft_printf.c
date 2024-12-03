/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:20:11 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:23 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "./inc/ft_printf.h"
#include "./libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>

// ap = argument pointer
int	ft_printf(const char *s, ...)
{
	va_list	ap;
	t_flags	f;
	size_t	counter;

	counter = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			ft_init_flags(&f);
			s += 1;
			s += ft_parse_f(s, &f);
			ft_process_data_type(ap, s, &f, &counter);
		}
		else
		{
			ft_putchar(*s);
			counter++;
		}
		s++;
	}
	va_end(ap);
	return (counter);
}
