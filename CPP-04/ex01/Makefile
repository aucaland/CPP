NAME				= Animal

CC					= c++
FLAGS				= -Wall -Wextra -Werror -std=c++98
RM					= rm -rf

SRC_DIR				= srcs
OBJ_DIR				= objs
H_DIR				= incs

SRC_NAME			= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
INCS_NAME			= Animal.h Cat.h Dog.h WrongAnimal.h WrongCat.h Brain.h

OBJ_NAME			= $(SRC_NAME:%.cpp=%.o)

SRC 				= $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJ 				= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
INCS				= $(addprefix $(H_DIR)/,$(INCS_NAME))

## Rules ##

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@printf %b	"\n"
	@printf %b  "\033[1;35m-[$(NAME)]__Edit/Create .o in \033[0m  \033[0;32m[OK]\033[0m\n"
	@printf %b  "\r"
	@$(MODE)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp $(INCS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf %b "-\033[1;35m[$(NAME)]\033[0m__Compiling \033[1;92m$<\033[0m in \033[1;92m$@\033[0m..."
	@printf "\r"

clean:
	@$(RM) $(OBJ)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove objs file  \033[0m  \".o\"         \033[0;32m [OK] \033[0m\n"

fclean: clean
	@$(RM) $(NAME)
	@printf %b  "-\033[1;33m[$(NAME)]__Remove \033[0m             \"$(NAME)\"    \033[0;32m [OK] \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
