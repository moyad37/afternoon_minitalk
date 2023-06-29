/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:19 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/29 14:46:50 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_ok;

void	send_bit(unsigned char character, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (character >> bit & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(2, "Fehler beim Senden von SIGUSR1\n", 30);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(2, "Fehler beim Senden von SIGUSR2\n", 30);
				exit(1);
			}
		}
		usleep(50);
		bit--;
	}
}

void	send(int pid, char *msg)
{
	size_t			msg_len;
	unsigned char	character;
	size_t			i;

	i = 0;
	msg_len = ft_strlen(msg);
	while (i < msg_len)
	{
		character = msg[i];
		send_bit(character, pid);
		i++;
	}
}

void	send_null(int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(2, "Fehler beim Senden von SIGUSR2\n", 30);
			exit(1);
		}
		usleep(50);
		bit--;
	}
}

void	handler_sig(int signal, siginfo_t *info, void *ucontent)
{
	(void)ucontent;
	(void)info;
	if (signal == SIGUSR1)
	{
		g_ok = 1;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	if (check_args(ac, av) == 1)
	{
		act.sa_sigaction = &handler_sig;
		act.sa_flags = SA_SIGINFO;
		pid = ft_atoi(av[1]);
		if (sigaction(SIGUSR1, &act, NULL) == -1)
			write(2, "Error by receive signal from server\n", 36);
		send(pid, av[2]);
		send_null(pid);
	}
	return (0);
}
