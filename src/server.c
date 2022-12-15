/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:32:12 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/15 10:46:55 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// SigAction requires 3 args, even though we care about 2. Hence the (void)x .

static void	ft_sig_handler(int signal, siginfo_t *info, void *x)
{
	static int	bit;
	static int	i;

	(void)x;
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

/* Notes for later: I can't think of any situation where ./server needs to 
process an argument, so I'm going to set it to void and see what happens. 
--Addendum: seems to work just fine. Leaving as is.

--Addendum #2: In order to handle a "return" signal, had to impliment 
"sigaction", because we need to determine the sender's PID automatically.
Not currently setting any of the other "flags" in the struct, that may
or may not be adjusted in the future if there are protection issues.	*/

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID:\t%d\n", pid);
	ft_printf("Waiting...\n");
	sa.sa_sigaction = ft_sig_handler;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
