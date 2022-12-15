/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:32:12 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/15 10:21:43 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_sig_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)s;
	if (signal == SIGUSR1)
		i |= (0b1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (i == 0)
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		i = 0;
	}
}

/* Notes for later: I can't think of any siguation where ./server needs to 
process an argument, so I'm going to set it to void and see what happens. */

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID:\t%d\n", pid);
	ft_printf("Waiting...\n");
	sa.sa_sigaction = ft_sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
