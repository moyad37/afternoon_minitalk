// #include "libft/libft.h"
// #include <signal.h>
// #include <sys/types.h>

// int		ok;
// int	ft_isstringdigit(char *str)
// {
// 	int	i;
// 	int	res;

// 	i = 0;
// 	res = 0;
// 	while (str[i])
// 	{
// 		if (ft_isdigit(str[i]) == 1)
// 			res = 1;
// 		else
// 			return (0);
// 		i++;
// 	}
// 	return (res);
// }

// void	send_msg(int server_pid, char *msg)
// {
// 	unsigned char	character;
// 	int				bit;
//     ok = 1;
// 	while (*msg)
// 	{
// 		character = *msg;
// 		bit = 8;
// 		while (bit--)
// 		{
// 			if (character & 0b10000000)
// 			{
// 				kill(server_pid, SIGUSR1);
// 				if (ok == 0)
// 				{
// 					write(2, "ERROR 1\n", 8);
// 				}
// 				ok = 0;
// 			}
// 			else
// 			{
// 				kill(server_pid, SIGUSR2);
// 				if (ok == 0)
// 				{
// 					write(2, "ERROR 2\n", 8);
// 				}
// 				ok = 0;
// 			}
// 			usleep(50);
// 			character <<= 1;
// 		}
// 		msg++;
// 	}
// }

// void	send_null(int server_pid)
// {
// 	int		bit;
// 	char	null;

// 	bit = 7;
// 	null = '\0';
// 	while (bit >= 0)
// 	{
// 		if (null >> bit & 1)
// 			kill(server_pid, SIGUSR1);
// 		else
// 			kill(server_pid, SIGUSR2);
// 		usleep(400);
// 		bit--;
// 	}
// }

// void	handler_sig(int signal, siginfo_t *info, void *ucontent)
// {
// 	(void)ucontent;
// 	(void)info;
// 	if (signal == SIGUSR1)
// 	{
// 		printf("ok ");
// 		ok = 1;
// 		//exit(1);
// 	}
// }

// int	check_input(int ac, char **av)
// {
// 	int	correct_input;

// 	correct_input = 0;
// 	if (ac != 3)
// 		printf("%s\n",
// 				"Bitte überprüfen Sie die Eingabe → ./client <PID> <Nachricht>");
// 	else if (!ft_isstringdigit(av[1]))
// 	{
// 		printf("%s", "Bitte überprüfen Sie die PID");
// 		printf("%s\n", " → Sie sollte nur aus Zahlen bestehen.");
// 	}
// 	else if (*av[2] == 0)
// 		printf("%s\n", "Bitte geben Sie eine nicht leere Nachricht ein.");
// 	else
// 		correct_input = 1;
// 	return (correct_input);
// }

// int	main(int argc, char **argv)
// {
// 	int server_pid;
// 	char *msg;
// 	struct sigaction sa_newsig;

// 	if (check_input(argc, argv) == 1)
// 	{
// 		sa_newsig.sa_sigaction = &handler_sig;
// 		sa_newsig.sa_flags = SA_SIGINFO;
// 		server_pid = ft_atoi(argv[1]);
// 		msg = argv[2];
// 		if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
// 			printf("%s\n", "Fehler → SIGUSR1 konnte nicht gesendet werden");
// 		send_msg(server_pid, msg);
// 		//free(msg);
// 		send_null(server_pid);
// 	}
// 	// while (1)
// 	//     pause();
// 	return (0);
// }










































#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>

int ok;

int ft_isstringdigit(char *str)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (str[i])
    {
        if (ft_isdigit(str[i]) == 1)
            res = 1;
        else
            return (0);
        i++;
    }
    return (res);
}

void send_msg(int server_pid, char *msg)
{
    unsigned char character;
    int bit;
    ok = 1;
    while (*msg)
    {
        character = *msg;
        bit = 8;
        while (bit--)
        {
            if (character & 0b10000000)
            {
                if (kill(server_pid, SIGUSR1) == -1)
                {
                    write(2, "ERROR kill 1\n", 14);
                    exit(1);
                }
                usleep(200);
                if (ok == 0)
                {
                    write(2, "ERROR 1\n", 8);
                    exit(1);
                }
                ok = 0;
            }
            else
            {
                if (kill(server_pid, SIGUSR2) == -1)
                {
                    write(2, "ERROR kill 2\n", 14);
                    exit(1);
                }
                usleep(200);
                if (ok == 0)
                {
                    write(2, "ERROR 2\n", 8);
                    exit(1);
                }
                ok = 0;
            }
            usleep(50);
            character <<= 1;
        }
        msg++;
    }
}

void send_null(int server_pid)
{
    int bit;
    char null;

    bit = 7;
    null = '\0';
    while (bit >= 0)
    {
        if (null >> bit & 1)
        {
            if (kill(server_pid, SIGUSR1) == -1)
            {
                write(2, "ERROR 0\n", 8);
                exit(1);
            }
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
            {
                write(2, "ERROR 0\n", 8);
                exit(1);
            }
        }
        usleep(400);
        bit--;
    }
}

void handler_sig(int signal, siginfo_t *info, void *ucontent)
{
    (void)ucontent;
    (void)info;
    if (signal == SIGUSR1)
    {
        ok = 1;
    }
}

int check_input(int ac, char **av)
{
    int correct_input;

    correct_input = 0;
    if (ac != 3)
        printf("%s\n", "Bitte überprüfen Sie die Eingabe → ./client <PID> <Nachricht>");
    else if (!ft_isstringdigit(av[1]))
    {
        printf("%s", "Bitte überprüfen Sie die PID");
        printf("%s\n", " → Sie sollte nur aus Zahlen bestehen.");
    }
    else if (*av[2] == 0)
        printf("%s\n", "Bitte geben Sie eine nicht leere Nachricht ein.");
    else
        correct_input = 1;
    return (correct_input);
}

int main(int argc, char **argv)
{
    int server_pid;
    char *msg;
    struct sigaction sa_newsig;

    if (check_input(argc, argv) == 1)
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


