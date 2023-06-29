/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:27 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/29 16:12:22 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_save_char	g_my;

void	*ft_mod_memset(void *b, int c, size_t len)
{
	unsigned char	*f;
	size_t			i;

	f = b;
	i = 0;
	while (i < len && f[i] != '\0')
	{
		i++;
	}
	while (i < len)
	{
		f[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	handler_sig(int signal, siginfo_t *info, void *ucontent)
{
	static int				bit;
	static unsigned char	character;

	(void)ucontent;
	if (signal == SIGUSR1)
		character |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (g_my.message_size + 1 >= MAX || character == '\0')
		{
			write(1, g_my.message, g_my.message_size);
			g_my.message_size = 0;
			ft_mod_memset(g_my.message, 0, sizeof(g_my.message));
		}
		g_my.message[g_my.message_size] = character;
		g_my.message_size++;
		bit = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					server_pid;
	struct sigaction	sa;

	(void)argv;
	server_pid = getpid();
	sa.sa_sigaction = &handler_sig;
	sa.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("%s\n", "Bitte überprüfen Sie die Eingabe → ./server");
		return (0);
	}
	ft_printf("%s%d\n", "Server PID: ", server_pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("%s\n", "Fehler → SIGUSR1 konnte nicht gesendet werden");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("%s\n", "Fehler → SIGUSR2 konnte nicht gesendet werden");
	while (1)
		pause();
	return (0);
}
