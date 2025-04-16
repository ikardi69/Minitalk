/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:25:21 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/16 16:08:02 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (!((c >> i) & 1))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

int	check_arg(char *pid)
{
	int i;

	i = 0;
	while (pid[i])
	{
		if (pid[i] < '0' || pid[i] > '9')
			return (ft_putstr_fd("ERROR : PID can't have characters\n", 2), exit(1), 0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int pid;
	int i;

	if (argc == 3)
	{
		if (!check_arg(argv[1]))
			return (1);
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			return (ft_putstr_fd("ERROR : PID cant be a negative number.\n", 2), 1);
		i = 0;
		while (argv[2][i])
		{
			send_byte(pid, argv[2][i]);
			i++;
		}
		// send_byte(pid, '\n');
		send_byte(pid, '\0');
	}
	else
	{
		ft_putstr_fd("ERROR try ./client <PID> <MESSAGE>\n", 2);
		return (1);
	}
	return (0);
}
