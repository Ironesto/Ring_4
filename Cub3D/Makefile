NAME		= cub3d
SRC			:= $(wildcard ./mandatory/*.c)

OBJS		= $(SRC:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft
RM			= rm -f

BLK = \e[0;30m
RED = \e[0;31m
GRN = \e[0;32m
YEL = \e[0;33m
BLU = \e[0;34m
MAG = \e[0;35m
CYN = \e[0;36m
WHT = \e[0;37m

RST = \e[0m

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	@echo "$(YEL)make: work in progress$(RST)"
	@make -C $(LIBFT_PATH)
	@$(CC) $(OBJS) $(LIBFT_PATH)/libft.a $(G) -o $(NAME)
	@echo "$(GRN)ALL COMPILED SUCCESSFULLY$(RST)"

clean:
	@echo "$(BLU)cleaning...$(RST)"
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean:
	@echo "$(YEL)cleaning... $(RED)ALL$(RST)"
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS) $(NAME)
	@echo "$(GRN)ALL CLEANED SUCCESSFULLY$(RST)"

re: fclean all