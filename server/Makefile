CXX=	g++

NAME=		klServer

SRC=		src/main.cpp		\
		src/Connexion.cpp	\
		src/Client.cpp

IDIRS=		./inc/

CXXFLAGS=	-W -Wall -Werror -I$(IDIRS)

OBJS=		$(SRC:.cpp=.o)

RM=		rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CXX) -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
		$(RM) $(OBJS)

fclean:     	clean
		$(RM) $(NAME)

re:		fclean all
