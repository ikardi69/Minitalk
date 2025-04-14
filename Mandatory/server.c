/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:16:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/14 18:29:53 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

void	signal_handler(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (sig == 	SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction sa;
	(void)argv;

	if (argc != 1)
	{
		ft_putstr_fd("ERROR try ./server\n", 2);
		return (1);
	}
	// sa = malloc(sizeof(struct sigaction));
	// if (!sa)
	// 	return (ft_putstr_fd(2, "Allocation error\n"), 1);
	sa.sa_handler = signal_handler;
	sigemptyset(&(sa.sa_mask));
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) < 0 ||
		sigaction(SIGUSR2, &sa, NULL))
		return (ft_putstr_fd(" Failed tpo set up signal handler\n", 2), 1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
