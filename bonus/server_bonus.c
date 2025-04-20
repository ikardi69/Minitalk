/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:16:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/20 17:01:21 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <signal.h>

void	signal_handler(int sig, siginfo_t *info, void *n)
{
	static int	i = 0;
	static char	c = 0;

	(void)n;
	if (sig == SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
			ft_putchar('\n');
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("ERROR try ./server\n", 2);
		return (1);
	}	
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		sleep(1);
}
