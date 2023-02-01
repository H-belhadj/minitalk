SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = 

%.o: %.c
	$(CC) -c $(CFLAGS) $?

NAME: server client 

all: $(NAME)


server: server.o 
	$(CC) -o $@ $< 

client: client.o 
	$(CC) -o $@ $< 

 

clean:
	rm -f $(OBJECTS)
	
fclean: clean
	rm -f server client 

re: fclean all

.PHONY: all  clean fclean re
