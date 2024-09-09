/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:54:03 by elefonta          #+#    #+#             */
/*   Updated: 2024/02/22 10:56:28 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	arguments;
	int		count;

	count = 0;
	i = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if ((ft_strchr(AUTH_ARGS, format[i]) == NULL) && write(1, "%", 1))
			{
				count++;
				continue ;
			}
			count += ft_print_args(format[i], arguments);
			i++;
		}
		else
			count += ft_print_char(format[i++]);
	}
	va_end(arguments);
	return (count);
}

int	ft_print_args(char type, va_list argument)
{
	if (type == 'c')
		return (ft_print_char(va_arg(argument, int)));
	if (type == 's')
		return (ft_print_str(va_arg(argument, char *)));
	if (type == 'd' || type == 'i')
		return (ft_print_nbr(va_arg(argument, int)));
	if (type == '%')
		return (ft_print_char('%'));
	if (type == 'u')
		return (ft_print_unsigned(va_arg(argument, unsigned int)));
	if (type == 'x')
		return (ft_print_nbr_base(va_arg(argument, unsigned int),
				LOWER_HEX, type));
	if (type == 'X')
		return (ft_print_nbr_base(va_arg(argument, unsigned int),
				UPPER_HEX, type));
	if (type == 'p')
		return (ft_print_nbr_base((unsigned long long)va_arg(argument, void *),
				LOWER_HEX, type));
	return (0);
}
