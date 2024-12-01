/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 15:44:16 by dmlasko           #+#    #+#             */
/*   Updated: 2024/07/26 15:03:00 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_intlen(long n, const char *base)
{
	int					len;
	unsigned long int	current_power;

	len = 1;
	current_power = 1;
	while (n / ft_strlen(base) >= current_power)
	{
		current_power *= ft_strlen(base);
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long nb, const char *base)
{
	int				len;
	unsigned long	number;
	char			*str;

	number = (unsigned long) nb;
	len = ft_intlen(number, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = base[number % ft_strlen(base)];
		number = number / ft_strlen(base);
		len--;
	}
	return (str);
}

char	*ft_itoa_base_signed(long nb, const char *base)
{
	int		len;
	char	*str;
	long	number;

	number = nb;
	len = ft_intlen(number, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[len - 1] = base[number % ft_strlen(base)];
		number = number / ft_strlen(base);
		len--;
	}
	return (str);
}
