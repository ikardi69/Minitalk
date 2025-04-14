CC = cc
FLAGS = -Wall -Wextra -Werror

NAME_S = server
NAME_C = client

MANDATORY_DIR = Mandatory/
MANDATORY_HEADER = $(MANDATORY_DIR)minitalk.h

SRCS_SERV = $(MANDATORY_DIR)server.c \
		$(MANDATORY_DIR)tools.c \
		$(MANDATORY_DIR)putchar.c

SRCS_CL = $(MANDATORY_DIR)client.c \
		$(MANDATORY_DIR)tools.c \
		$(MANDATORY_DIR)putchar.c
OBJS_SERV = $(SRCS_SERV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_SERV) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -o $(NAME_S) $(OBJS_SERV)

$(NAME_C): $(OBJS_CL) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -o $(NAME_C) $(OBJS_CL)

clean:
	rm -f $(OBJS_SERV) $(OBJS_CL)

fclean: clean
	rm -f $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re