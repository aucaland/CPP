NAME	= megaphone

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

## Rules ##

all:		$(NAME)

$(NAME):	megaphone.cpp
	@$(CC) $(FLAGS) megaphone.cpp -o  $(NAME)
	@printf %b	"\n"
	@printf %b  "\033[1;35m-[$(NAME)]__Edit/Create .o in \033[0m  \033[0;32m[OK]\033[0m\n"
	@printf %b  "\r"
	@$(MODE)

clean:
	@$(RM) $(NAME)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m\n"

re: fclean all

.PHONY: all clean fclean re