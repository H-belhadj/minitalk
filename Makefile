CLIENT_SRCS := client.c
SERVER_SRCS := server.c
NAME := client
NAMES := server
CC := cc
FLAGS := -Wall -Wextra -Werror

all: $(NAME) $(NAMES)

$(NAME) : $(CLIENT_SRCS)
			$(CC) $(FLAGS) $(CLIENT_SRCS) -o client

$(NAMES) : $(SERVER_SRCS)
			$(CC) $(FLAGS) $(SERVER_SRCS) -o server


clean:
	rm -rf client
	rm -rf server

fclean: clean

re: clean all