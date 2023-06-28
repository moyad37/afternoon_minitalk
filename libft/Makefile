# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanssou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 15:03:58 by mmanssou          #+#    #+#              #
#    Updated: 2022/10/14 13:33:22 by mmanssou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror
SRC =  ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_itoa.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_strtrim.c\
	ft_split.c\
	ft_print_char.c\
	ft_print_hex.c\
	ft_print_nbr.c\
	ft_print_p0x.c\
	ft_print_string.c\
	ft_print_unsigned.c\
	ft_printf.c


OBJ = $(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?

%.o: %.c 
	$(CC) -c $(CFLAGS) $?

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ)
fclean:	clean
	rm -f $(NAME)
re:	fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
