/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:18:43 by mteffahi          #+#    #+#             */
/*   Updated: 2025/04/14 18:22:44 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# define LL_MAX 9223372036854775807LL

int		ft_atoi(const char *str);
int		check_arg(char *pid);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif 
