/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:05:39 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/30 19:13:25 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	kll_f(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_byte	*new_char(char c)
{
	t_byte	*new;

	new = malloc(sizeof(t_byte));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->c = c;
	return (new);
}

void	ft_add_char(t_byte **head, t_byte *new)
{
	t_byte	*last;

	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	print_list(t_byte *head)
{
	t_byte	*tmp;

	tmp = head;
	while (tmp)
	{
		write(1, &tmp->c, 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
