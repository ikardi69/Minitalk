/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/27 18:11:00 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile int	g_ack = 0;

void	rep_handler(int signal)
{
	(void)signal;
	g_ack = 1;
}

void	send_byte(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if (!((c >> i) & 1))
		{
			if (kill(pid, SIGUSR1) == -1)
				kll_f();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				kll_f();
		}
		while (!g_ack)
			pause();
		i--;
	}
}

int	check_arg(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
		{
			ft_putstr_fd("ERROR : PID can't have characters\n", 2);
			return (exit(1), 0);
		}
		i++;
	}
	return (1);
}

void	sending_string(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(server_pid, str[i]);
		i++;
	}
	send_byte(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sa;

	if (argc == 3)
	{
		if (!check_arg(argv[1]))
			return (1);
		server_pid = ft_atoi(argv[1]);
		if (server_pid < 0)
			return (ft_putstr_fd("ERROR : PID cant be a negative number.\n", 2),
				1);
		sa.sa_handler = rep_handler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, 0);
		sending_string(server_pid, argv[2]);
	}
	else
	{
		ft_putstr_fd("ERROR try ./client <PID> <MESSAGE>\n", 2);
		return (1);
	}
	return (0);
}
