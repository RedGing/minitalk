/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:58:37 by femorell          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:39 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	g_check = 0;

static void	ft_sighandler(int signal)
{
	g_check = 0;
	(void)signal;
}

static void	ft_sendmsg(char c, int pid)
{
	int	i;	

	i = 0;
	while (i < 8)
	{
		while (g_check != 0)
			usleep(0);
		g_check = 1;
		if (c >> (7 - i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR1, ft_sighandler);
	signal(SIGUSR2, ft_sighandler);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 1)
			return (0);
		i = 0;
		while (av[2][i])
		{
			ft_sendmsg(av[2][i], pid);
			i++;
		}
		ft_sendmsg(0, pid);
	}
}
