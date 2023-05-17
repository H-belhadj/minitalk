/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelhadj <hbelhadj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:49:48 by hbelhadj          #+#    #+#             */
/*   Updated: 2023/02/07 22:35:14 by hbelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	binary_to_ascii(char *binary_string)
{
	int		i;
	int		len;
	char	ascii_char;

	i = 0;
	len = ft_strlen(binary_string);
	ascii_char = 0;
	while (i < len)
	{
		ascii_char = (ascii_char << 1) | (binary_string[i] - '0');
		if ((i + 1) % 8 == 0)
		{
			write(1, &ascii_char, 1);
			ascii_char = 0;
		}
		i++;
	}
}

void	handle_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	str[9];
	static int	i;
	static int	pid = 0;

	(void)context;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		str[0] = '\0';
		i = 0;
	}
	if (signum == SIGUSR2)
		str[i++] = '1';
	else
		str[i++] = '0';
	if (i == 8)
	{
		str[i] = '\0';
		binary_to_ascii(str);
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handle_sigusr;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
	{
		pause();
	}
}
