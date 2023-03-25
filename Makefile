NAME = main

SRCS = ./sources/main.cpp ./sources/average_age_persons.cpp ./sources/add_file.cpp ./sources/parse.cpp ./sources/person.cpp ./sources/check_json.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = g++ 
FLAGS = -Wall -Wextra
HEADER = ./includes/person.h

%.o: %.cpp $(HEADER) Makefile
	$(CXX) $(FLAGS) -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	$(CXX) $(OBJS) -o ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean
