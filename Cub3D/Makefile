NAME		= cub3d
SRC			:= $(wildcard ./mandatory/*.c)

OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft
RM			= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(OBJS) $(LIBFT_PATH)/libft.a $(G) -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean:
	make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS) $(NAME)

re: fclean all