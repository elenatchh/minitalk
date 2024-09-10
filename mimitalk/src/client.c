/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:18:40 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/10 15:46:20 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_signal;

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

void	send_binary(char caract, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((caract & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_signal == 0)
		{

		}
		g_signal = 0;
		i++;
	}
}

bool	true_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void	confirm_signal(int signal)
{
	if (signal == SIGUSR1)
		g_signal = 1;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	g_signal = 0;
	signal(SIGUSR1, confirm_signal);
	if (argc != 3)
		return (ft_printf("nombre mauvais d'arguments"), 0);
	if (true_pid(argv[1]) == false)
		return (ft_printf("pid mal ecrit"), 0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_binary(argv[2][i], pid);
		i++;
	}
	send_binary(0, pid);
	kill(pid, SIGUSR2);
}

