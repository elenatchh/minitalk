/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:18:40 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/09 14:59:53 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_atoi(const char *str)
{
	int	i ;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i ++;
	}
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

bool	true_pid(char *PID)
{
	int	i;

	i = 0;
	while (PID[i])
	{
		if (PID[i] < '0' || PID[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	PID; 
	
	
	if (argc != 2)
		return (ft_printf("nombre mauvais d'arguments"), 0);
	if (true_pid(argv[1]) == false)
		return (ft_printf("PID mal ecrit"), 0);
	PID = ft_atoi(argv[1]);
	kill(PID, SIGUSR1);
}


