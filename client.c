/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:05:01 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/02/07 22:40:18 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	r;
	int	sign;
	int	i;

	r = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * sign);
}

void	print_bin(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep (250);
	}
}

void	send_char(char *c, int pid)
{
	int	i;

	i = 0;
	while (c[i])
	{
		print_bin(c[i], pid);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	b;

	if (argc <= 2)
		return (0);
	b = ft_atoi (argv[1]);
	if (b <= 0)
		return (0);
	send_char(argv[2], b);
}
