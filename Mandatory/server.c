/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:16:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/16 16:08:13 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	signal_handler(int sig)
{
	static int				i = 0;
	static char	c = 0;

	if (sig == 	SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		// ft_putchar(c);
		write(1, &c, 1);
		if (c == '\0')
			ft_putchar('\n');
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	// struct sigaction sa;
	(void)argv;

	if (argc != 1)
	{
		ft_putstr_fd("ERROR try ./server\n", 2);
		return (1);
	}	
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	// sa.sa_handler = signal_handler;
	// sigemptyset(&(sa.sa_mask));
	// sa.sa_flags = SA_RESTART;
	// if (sigaction(SIGUSR1, &sa, NULL) == -1 ||
	// 	sigaction(SIGUSR2, &sa, NULL) == -1)
	// 	return (ft_putstr_fd(" Failed to set up signal handler\n", 2), 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	// while (1)
	// 	pause();
	while (1)
		sleep(1);
}
