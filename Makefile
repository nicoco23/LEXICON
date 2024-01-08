SRC		=		main.cpp 	\

OBJS		=		$(SRC:.cpp=.o)

NAME		=		lexicon

all:		$(NAME)

$(NAME):	$(OBJS)
		make -C ./lib/my
		g++ $(OBJS) -o $(NAME) -L ./lib/my -lmy

clean:
		rm -f $(OBJS)
		rm -f units-tests-*
		make clean -C ./lib/my

fclean:		clean
		rm -f $(NAME)
		make fclean -C ./lib/my

re: 		fclean all