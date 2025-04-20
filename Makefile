CC = cc
FLAGS = -Wall -Wextra -Werror

NAME_S = server
NAME_C = client

NAME_S_BNS = server_bonus
NAME_C_BNS = client_bonus

MANDATORY_DIR = Mandatory/
BONUS_DIR = bonus/
MANDATORY_HEADER = $(MANDATORY_DIR)minitalk.h
BONUS_HEADER = $(BONUS_DIR)minitalk_bonus.h

SRCS_SERV = $(MANDATORY_DIR)server.c \
		$(MANDATORY_DIR)tools.c \
		$(MANDATORY_DIR)putchar.c

SRCS_SERV_BNS = $(BONUS_DIR)server_bonus.c \
			$(BONUS_DIR)tools_bonus.c \
			$(BONUS_DIR)putchar_bonus.c

SRCS_CL = $(MANDATORY_DIR)client.c \
		$(MANDATORY_DIR)tools.c \
		$(MANDATORY_DIR)putchar.c

SRCS_CL_BNS = $(BONUS_DIR)client_bonus.c \
			$(BONUS_DIR)tools_bonus.c \
			$(BONUS_DIR)putchar_bonus.c

OBJS_SERV = $(SRCS_SERV:.c=.o)
OBJS_CL = $(SRCS_CL:.c=.o)

OBJS_SERV_BNS = $(SRCS_SERV_BNS:.c=.o)
OBJS_CL_BNS = $(SRCS_CL_BNS:.c=.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJS_SERV) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -o $(NAME_S) $(OBJS_SERV)

$(NAME_C): $(OBJS_CL) $(MANDATORY_HEADER)
	$(CC) $(FLAGS) -o $(NAME_C) $(OBJS_CL)

bonus: $(NAME_S_BNS) $(NAME_C_BNS)

$(NAME_S_BNS): $(OBJS_SERV_BNS) $(BONUS_HEADER)
	$(CC) $(FLAGS) -o $(NAME_S_BNS) $(OBJS_SERV_BNS)

$(NAME_C_BNS): $(OBJS_CL_BNS) $(BONUS_HEADER)
	$(CC) $(FLAGS) -o $(NAME_C_BNS) $(OBJS_CL_BNS)

clean:
	rm -f $(OBJS_SERV) $(OBJS_CL) $(OBJS_SERV_BNS) $(OBJS_CL_BNS)

fclean: clean
	rm -f $(NAME_S) $(NAME_C) $(NAME_C_BNS) $(NAME_S_BNS)

re: fclean all

.PHONY: all clean fclean re