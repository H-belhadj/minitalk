/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:56 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/01/30 15:35:36 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

void	binary_to_ascii(char *binary_string);
int		ft_atoi(char *str);
void	handle_sigusr(int signum, siginfo_t *info, void *context);
int		ft_atoi(char *str);
void	print_bin(char c, int pid);
void	send_char(char *c, int pid);
void	ft_putnbr(int n);
int		ft_strlen(char *str);

#endif
