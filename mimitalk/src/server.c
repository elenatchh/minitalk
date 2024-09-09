/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:17:43 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/09 15:00:31 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void receive_binary(int signal, siginfo_t *s, void *v)
{
    (void)v;
    (void)s;
	
	printf("Lance ou pas");
	
    if (signal == SIGUSR1)
        write(1, "C'est le signal 1\n", 18);
}

int	main()
{
	struct sigaction s;

	(void)s;
	memset(&s, 0, sizeof(s));
	s.sa_sigaction = receive_binary;
	s.sa_flags = SA_SIGINFO;
	(void)s;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	ft_printf("%d\n",getpid());
	printf("%d\n",getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
