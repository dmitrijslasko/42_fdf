/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:45:04 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:15 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

static void	ft_print(char *ptr_address, t_flags *f)
{
	if (f->align_left)
	{
		ft_putstr("0x");
		while (f->preceding_0_len--)
			ft_putchar('0');
		ft_putstr(ptr_address);
		while (f->space_len--)
			ft_putchar(' ');
	}
	else
	{
		while (f->space_len--)
			ft_putchar(' ');
		ft_putstr("0x");
		while (f->preceding_0_len--)
			ft_putchar('0');
		ft_putstr(ptr_address);
	}
}

void	ft_putptr_base(void *p, t_flags *f, size_t *counter)
{
	char	*ptr_address;

	if (p == NULL)
	{
		ptr_address = "(nil)";
		ft_putstr_new(ptr_address, f, counter);
		return ;
	}
	else
		ptr_address = ft_itoa_base_signed((long) p, "0123456789abcdef");
	f->space_len = f->min_width - ft_strlen(ptr_address) - ft_strlen("0x");
	f->preceding_0_len = f->prcsn_len - ft_strlen(ptr_address);
	if (f->preceding_0_len < 0) 
		f->preceding_0_len = 0;
	f->space_len -= f->preceding_0_len;
	if (f->space_len < 0) 
		f->space_len = 0;
	*counter += f->preceding_0_len + f->space_len + ft_strlen(ptr_address) + 2;
	ft_print(ptr_address, f);
	free(ptr_address);
}
