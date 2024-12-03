/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:22:10 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/25 19:48:40 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	int			flag_error;
	int			align_left;
	int			di_precdng_sp;
	int			di_precdng_pl;
	int			x_preceding_symbols;
	int			min_width;
	int			prcsn;
	int			prcsn_len;
	int			fill_char;
	int			preceding_0_len;
	int			space_len;
	int			is_neg;
	char		*base;
}	t_flags;

int		ft_printf(const char *s, ...);

void	ft_process_data_type(va_list ap, const char *s, \
		t_flags *f, size_t *count);

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	ft_putsubstr(char *s, int n);

void	ft_putchar_new(char c, t_flags *f, size_t *counter);

void	ft_putstr_new(char *s, t_flags *f, size_t *counter);

void	ft_putptr_base(void *p, t_flags *f, size_t *counter);

void	ft_puthex(unsigned int nbr, char *base, size_t *counter);

void	print_upper(char *s);

size_t	ft_parse_f(const char *s, t_flags *f);

//void	ft_apply_f(t_flags *f, char *base, size_t *counter);

void	ft_init_flags(t_flags *f);

size_t	ft_putnbr_base(long n, int type, char *base, t_flags *f);

char	*ft_itoa_base(long nb, const char *base);

char	*ft_itoa_base_signed(long nb, const char *base);

int		ft_intlen(long n, const char *base);

int		ft_max(int num1, int num2);

void	ft_putpercent(t_flags *f, size_t *counter);

#endif