NAME = ft_retro

FLAGS = clang++ #-Wall -Wextra -Werror -Wuninitialized

OBJ = obj/Hero.o obj/main.o obj/Window.o obj/Entity.o obj/Enemy.o

$(NAME): $(OBJ)
		$(FLAGS) -lncurses -o $(NAME) $(OBJ)

all:
	make $(NAME)

$(OBJ): obj/%.o: src/%.cpp
		$(FLAGS) -c src/$*.cpp -o $@

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all