/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:34:31 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:41:59 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include "../libft/libft.h"

static void	ft_apply_f(long n, int type, t_flags *f, size_t *counter)
{
	if (f->di_precdng_pl && type == 1)
	{
		ft_putchar('+');
		f->di_precdng_pl = 0;
	}
	if (f->di_precdng_sp && type == 2)
	{
		ft_putchar(' ');
		f->di_precdng_pl = 0;
	}
	if (f->x_preceding_symbols && n > 0 && type == 1)
	{
		if (!ft_strncmp(f->base, "0123456789ABCDEF", 16))
			ft_putstr("0X");
		else if (!ft_strncmp(f->base, "0123456789abcdef", 16))
			ft_putstr("0x");
		*counter += 2;
	}
}

void	ft_print_left(long n, char *n_str, t_flags *f, size_t *counter)
{
	if (!f->is_neg)
		ft_apply_f(n, 2, f, counter);
	if (f->is_neg)
		ft_putchar('-');
	else
		ft_apply_f(n, 1, f, counter);
	while (f->preceding_0_len--)
		ft_putchar('0');
	if (!n && !f->prcsn_len && f->prcsn && f->min_width)
		ft_putchar(' ');
	else if (!f->prcsn || f->min_width || f->prcsn_len)
		ft_putstr(n_str);
	else if ((n && (f->prcsn || f->min_width || f->prcsn_len)))
		ft_putstr(n_str);
	while (f->space_len--)
		ft_putchar(f->fill_char);
}

void	ft_print_right(long n, char *n_str, t_flags *f, size_t *counter)
{
	if (f->is_neg && f->fill_char == '0')
		ft_putchar('-');
	if (!f->is_neg)
		ft_apply_f(n, 2, f, counter);
	if (n >= 0 && f->fill_char == '0')
		ft_apply_f(n, 1, f, counter);
	while (f->space_len--)
		ft_putchar(f->fill_char);
	if (n >= 0 && f->fill_char == ' ')
		ft_apply_f(n, 1, f, counter);
	if (f->is_neg && f->fill_char != '0')
		ft_putchar('-');
	while (f->preceding_0_len--)
		ft_putchar('0');
	if (!n && !f->prcsn_len && f->prcsn && f->min_width)
		ft_putchar(' ');
	else if (!f->prcsn || f->min_width || f->prcsn_len)
		ft_putstr(n_str);
	else if ((n && (f->prcsn || f->min_width || f->prcsn_len)))
		ft_putstr(n_str);
}

char	*ft_nbr_to_str(long n, t_flags *f)
{
	char	*n_str;
	char	*n_itoa;

	n_itoa = ft_itoa(n);
	n_str = ft_substr(n_itoa, f->is_neg, ft_strlen(n_itoa) - f->is_neg);
	free(n_itoa);
	return (n_str);
}

size_t	ft_putnbr_base(long n, int type, char *base, t_flags *f)
{
	char	*n_str;
	int		calc;
	size_t	counter;

	counter = 0;
	if (n < 0)
		f->is_neg = 1;
	if (type == 1)
		n_str = ft_nbr_to_str(n, f);
	else
		n_str = ft_itoa_base(n, base);
	f->base = base;
	f->preceding_0_len = ft_max(f->prcsn_len - ft_strlen(n_str), 0);
	calc = ft_strlen(n_str) + f->is_neg + (n >= 0) * \
		f->di_precdng_pl + (n >= 0) * f->di_precdng_sp;
	f->space_len = ft_max(f->min_width - f->preceding_0_len - calc, 0);
	counter += f->preceding_0_len + f->space_len + calc;
	counter -= (n == 0 && f->prcsn && !f->min_width && !f->prcsn_len);
	if (f->align_left)
		ft_print_left(n, n_str, f, &counter);
	if (!f->align_left)
		ft_print_right(n, n_str, f, &counter);
	free(n_str);
	return (counter);
}
