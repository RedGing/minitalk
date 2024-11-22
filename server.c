/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femorell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:58:46 by femorell          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:49 by femorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void	ft_sighandler(int signal, siginfo_t *info, void *ucontext)
{
	static char	msg;
	static int	i;

	(void)ucontext;
	if (signal == SIGUSR1)
		msg |= (1 << (7 - i));
	i++;
	if (i >= 8)
	{
		if (msg == 0)
			write (1, "\n", 1);
		else
			write (1, &msg, 1);
		msg = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = ft_sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	while (1)
		sleep(0);
}
