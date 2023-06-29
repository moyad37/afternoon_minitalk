/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanssou <mmanssou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:55:27 by mmanssou          #+#    #+#             */
/*   Updated: 2023/06/29 17:00:34 by mmanssou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_save_char	g_my;

// void	*ft_mod_memset(void *b, int c, size_t len)
// {
// 	unsigned char	*f;
// 	size_t			i;

// 	f = b;
// 	i = 0;
// 	while (i < len && f[i] != '\0')
// 	{
// 		i++;
// 	}
// 	while (i < len)
// 	{
// 		f[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }

void	handler_sig(int signal, siginfo_t *info, void *ucontent)
{
	//static int				bit;
	static unsigned char	character;

	(void)ucontent;
	if (signal == SIGUSR1)
		character |= (1 << (7 - g_my.count));
	g_my.count++;
	if (g_my.count == 8)
	{
		if (g_my.message_size + 1 >= MAX || character == '\0')
		{
			write(1, g_my.message, g_my.message_size);
			g_my.message_size = 0;
			ft_bzero(g_my.message, sizeof(g_my.message));
		}
		g_my.message[g_my.message_size] = character;
		g_my.message_size++;
		g_my.count = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	(void)argv;
	pid = getpid();
	act.sa_sigaction = &handler_sig;
	act.sa_flags = SA_SIGINFO;
	if (argc != 1)
	{
		ft_printf("check your args\n");
		return (0);
	}
	write(1, "pid = ", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		ft_printf("SIGUSR2 error\n");
	while (1)
		pause();
	return (0);
}
