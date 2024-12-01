/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_data_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:03:03 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:08 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"
//• %c Prints a single character.
//• %s Prints a string (as defined by the common C convention).
//• %p The void * pointer argument has to be printed in hexadecimal format.
//• %d Prints a decimal (base 10) number.
//• %i Prints an integer in base 10.
//• %u Prints an unsigned decimal (base 10) number.
//• %x Prints a number in hexadecimal (base 16) lowercase format.
//• %X Prints a number in hexadecimal (base 16) uppercase format.
//• %% Prints a percent sign.

void	ft_process_data_type(va_list ap, const char *s, \
		t_flags *f, size_t *counter)
{
	if (*s == 'c')
		ft_putchar_new(va_arg(ap, int), f, counter);
	else if (*s == 's')
		ft_putstr_new(va_arg(ap, char *), f, counter);
	else if (*s == 'p')
		ft_putptr_base(va_arg(ap, void *), f, counter);
	else if (*s == 'd' || *s == 'i')
		*counter += ft_putnbr_base(va_arg(ap, int), 1, "0123456789", f);
	else if (*s == 'u')
		*counter += ft_putnbr_base((unsigned int)va_arg(ap, int), 2, \
			"0123456789", f);
	else if (*s == 'x')
		*counter += ft_putnbr_base((unsigned int)va_arg(ap, int), 3, \
			"0123456789abcdef", f);
	else if (*s == 'X')
		*counter += ft_putnbr_base((unsigned int)va_arg(ap, int), 4, \
			"0123456789ABCDEF", f);
	else if (*s == '%')
	{
		ft_putchar('%');
		*counter += 1;
		s++;
	}
	s++;
}
