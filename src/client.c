/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:32:32 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/15 10:55:32 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	if (signal)
		ft_printf("Confirmation received.\n");
}

static void	ft_send_byte(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0b1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(SIG_DELAY);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Incorrect format.\n ./client {PID} {MESSAGE}\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		signal(SIGUSR2, ft_confirm);
		ft_send_byte(pid, argv[2][i]);
		i++;
	}
	ft_send_byte(pid, '\n');
	ft_send_byte(pid, 0);
	return (0);
}
