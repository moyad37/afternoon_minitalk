/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:19 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/29 17:00:49 by mmanssou         ###   ########.fr       */
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
		usleep(100);
		bit--;
	}
}

void	send_msg(int pid, char *msg)
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
		usleep(100);
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

int	main(int argc, char **argv)
{
	int					server_pid;
	char				*msg;
	struct sigaction	sa_newsig;

	if (check_args(argc, argv) == 1)
	{
		sa_newsig.sa_sigaction = &handler_sig;
		sa_newsig.sa_flags = SA_SIGINFO;
		server_pid = ft_atoi(argv[1]);
		msg = argv[2];
		if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
			printf("%s\n", "Fehler → SIGUSR1 konnte nicht gesendet werden");
		send_msg(server_pid, msg);
		send_null(server_pid);
	}
	return (0);
}
