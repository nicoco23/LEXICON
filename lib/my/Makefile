SRC			=			player.cpp\

OBJS		=			$(SRC:.cpp=.o)

NAME		=			libmy.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
	rm -f *.o 

fclean:		clean
			rm -f $(NAME) *~ *# *.out *.a

re: 		fclean all