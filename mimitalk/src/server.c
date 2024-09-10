/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:17:43 by elefonta          #+#    #+#             */
/*   Updated: 2024/09/10 13:56:45 by elefonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

char	*ft_charjoin(char *s1, char caract)
{
	char	*result;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	result = malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!result)
		return (NULL);
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = caract;
	i++;
	result[i] = '\0';
	free(s1);
	return (result);
}


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

	int caract;
	int i;

	caract = 0;
	i = 0;
    if (signal == SIGUSR1)
		caract |= (1 << i);
	i++;
	if (i == 8)
		printf("test : %c", caract);
}

int	main()
{
	struct sigaction s;

	(void)s;
	ft_bzero(&s, sizeof(s));
	s.sa_sigaction = receive_binary;
	s.sa_flags = SA_SIGINFO;
	(void)s;
	sigaction(SIGUSR1, &s, NULL);
	sigaction(SIGUSR2, &s, NULL);
	ft_printf("%d\n",getpid());
	
	
	while (true)
	{
		
	}
	return (0);
}
