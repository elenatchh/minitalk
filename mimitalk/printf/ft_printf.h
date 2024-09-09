/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:51:07 by elefonta          #+#    #+#             */
/*   Updated: 2024/02/21 12:24:21 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# define LOWER_HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"
# define AUTH_ARGS "cspdiuxX%"

int			ft_printf(const char *format, ...);
int			ft_print_args(char type, va_list argument);

int			ft_print_char(char c);
int			ft_print_str(char *s);
int			ft_print_unsigned(unsigned int nb);
int			ft_print_nbr(int nb);
int			ft_print_nbr_base(unsigned long long nb, char *base, char type);
int			ft_strlen(const char *str);
const char	*ft_strchr(const char *s, int c);

#endif