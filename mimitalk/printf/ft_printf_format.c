/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:27:56 by elefonta          #+#    #+#             */
/*   Updated: 2024/02/13 11:42:45 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 10)
	{
		count += ft_print_char(nb + '0');
	}
	else
	{
		count += ft_print_unsigned(nb / 10);
		count += ft_print_unsigned(nb % 10);
	}
	return (count);
}

int	ft_print_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb *= -1;
	}
	return (count + ft_print_unsigned(nb));
}

int	ft_print_nbr_base(unsigned long long nb, char *base, char type)
{
	int		count;
	size_t	base_length;

	count = 0;
	if (type == 'p')
	{
		if (nb)
		{
			count += ft_print_str("0x");
			type = 'x';
		}
		else
			return (ft_print_str("(nil)"));
	}
	base_length = ft_strlen(base);
	if (nb < base_length)
		count += ft_print_char(base[nb % base_length]);
	else
	{
		count += ft_print_nbr_base(nb / base_length, base, type);
		count += ft_print_nbr_base(nb % base_length, base, type);
	}
	return (count);
}
