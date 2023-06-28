// #include "libft/libft.h"
// #include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>

// #define MAX 10000

// typedef struct s_save_char
// {
// 	//int		bin[8];
// 	//int		c;
// 	//int		counter;
// 	char	message[MAX];
// 	//int		pid;
// 	size_t	message_size;
// }			t_save_char;
// t_save_char g_my;
// void handler_sig(int signal, siginfo_t *info, void *ucontent)
// {
//     static int bit;
//     static int character;
//     char c;
//     (void)ucontent;
//     if (signal == SIGUSR1)
//         character += 1 << (7 - bit);
//     bit++;
//     kill(info->si_pid, SIGUSR1);
//     if (bit == 8)
//     {
//         if(g_my.message_size + 1 >= MAX || character == '\0')
//         {   
//             write(1, g_my.message, g_my.message_size);
//             g_my.message_size = 0;
//             ft_memset(g_my.message , 0 , sizeof(g_my.message));
//         }
//         c = (char)character;
//         strncat(g_my.message, &c, 1); // Empfangenes Zeichen zur Nachricht hinzufügen
//         g_my.message_size++;
//         bit = 0;
//         character = 0;
//     }
// }

// int main(int argc, char **argv)
// {
//     int server_pid;
//     struct sigaction sa_newsig;

//     (void)argv;
//     server_pid = getpid();
//     sa_newsig.sa_sigaction = &handler_sig;
//     sa_newsig.sa_flags = SA_SIGINFO;
//     if (argc != 1)
//     {
//         printf("%s\n", "Bitte überprüfen Sie die Eingabe → ./server");
//         return 0;
//     }
//     printf("%s%d\n", "Server PID: ", server_pid);
//     if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
//         printf("%s\n", "Fehler → SIGUSR1 konnte nicht gesendet werden");
//     if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
//         printf("%s\n", "Fehler → SIGUSR2 konnte nicht gesendet werden");
//     while (1) // Auf den Empfang der Nachricht warten
//         pause();
//     //printf("Empfangene Nachricht: %s\n", received_msg);
//     return 0;
// }























#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX 1000000

typedef struct s_save_char
{
    char message[MAX];
    size_t message_size;
} t_save_char;

t_save_char g_my;

void	*ft_mod_memset(void *b, int c, size_t len)
{
	unsigned char *f = b;
    size_t i = 0;

    while (i < len && f[i] != '\0')
    {
        i++;

    }
    while (i < len)
    {
        f[i] = (unsigned char)c;
        i++;
    }
    return b;
}

void handler_sig(int signal, siginfo_t *info, void *ucontent)
{
static int bit = 0;
    static unsigned char character = 0;
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

int main(int argc, char **argv)
{
    int server_pid;
    struct sigaction sa_newsig;

    (void)argv;
    server_pid = getpid();
    sa_newsig.sa_sigaction = &handler_sig;
    sa_newsig.sa_flags = SA_SIGINFO;
    if (argc != 1)
    {
        printf("%s\n", "Bitte überprüfen Sie die Eingabe → ./server");
        return 0;
    }
    printf("%s%d\n", "Server PID: ", server_pid);
    if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
        printf("%s\n", "Fehler → SIGUSR1 konnte nicht gesendet werden");
    if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
        printf("%s\n", "Fehler → SIGUSR2 konnte nicht gesendet werden");
    while (1)
        pause();
    return 0;
}
