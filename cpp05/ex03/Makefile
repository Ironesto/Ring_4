NAME	= intern
SRC		= $(wildcard ./*.cpp)
OBJS	= $(SRC:.cpp=.o)
CC		= c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
RM		= rm -rf

BOLD	= \033[1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME) && printf "$(GREEN)$(BOLD)$(NAME) ready!\n$(RESET)"

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean :
	@$(RM) $(OBJS) && printf "$(YELLOW)All objects have been clean :)\n$(RESET)"

fclean : clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(NAME) $(GREEN)has been clean :)\n$(RESET)"

re : fclean all

.PHONY : all clean fclean re