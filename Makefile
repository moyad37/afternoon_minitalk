
FLAGS=-Werror -Wextra -Wall
SERVER=server
CLIENT=client
S_SRC=server.c
C_SRC=client.c
S_OBJS = $(S_SRC:.c=.o)
C_OBJS = $(C_SRC:.c=.o)
INCLUDES=libft/libft.a

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

%.o: %.c 
	${MAKE} -C libft all
	cc $(FLAGS) -c $< -o $@

$(SERVER) : $(S_SRC) $(INCLUDES)
	cc $(S_SRC) $(INCLUDES) -o $@

$(CLIENT) : $(C_SRC) $(INCLUDES)
	cc $(C_SRC) $(INCLUDES) -o $@

$(INCLUDES):
	${MAKE} -C libft

clean:
	${MAKE} -C libft/ clean
	rm -f $(S_OBJS) $(C_OBJS)
	
fclean: clean
	rm -f $(SERVER) $(CLIENT)
	${MAKE} -C libft fclean

re: fclean all

