SRC			=			player.cpp	\
						my_strcmp.cpp	\
						my_strcpy.cpp	\
						my_atoi.cpp	\
						card.cpp	\
						dictionnary.cpp	\

OBJS		=			$(SRC:.cpp=.o)

NAME		=			libmy.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			rm -f *.o

clean:
	rm -f *.o 

fclean:		clean
			rm -f $(NAME) *~ *# *.out *.a

re: 		fclean all