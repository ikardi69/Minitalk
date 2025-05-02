/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:16:24 by mteffahi          #+#    #+#             */
/*   Updated: 2025/05/01 16:15:39 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_reset(char *c, int *i)
{
	*c = 0;
	*i = 0;
}

void	pr_handler(t_byte *head)
{
	print_list(head);
	free_lst(head);
	head = NULL;
}

void	free_lst(t_byte *head)
{
	t_byte	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	tmp = NULL;
}

void	signal_handler(int sig, siginfo_t *info, void *n)
{
	static int		i;
	static char		c;
	static t_byte	*head = NULL;
	static pid_t	old_pid;

	(void)n;
	if (old_pid != info->si_pid)
	{
		ft_reset(&c, &i);
		free_lst(head);
		head = NULL;
		ft_putstr_fd("\n--> : ", 1);
		old_pid = info->si_pid;
	}
	if (sig == SIGUSR2)
		c |= (1 << (7 - i));
	i++;
	if (i == 8)
	{
		ft_add_char(&head, new_char(c));
		if (c == '\0')
			print_list(head);
		ft_reset(&c, &i);
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
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
}
