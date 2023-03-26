## EPITECH PROJECT, 2022
## BSQ Project
## File description:
## Makefile

SRC = 	src/lib_jam/lib_sprite/mouvement.cpp\
		src/lib_jam/lib_sprite/init_window_sprite.cpp\
		src/lib_jam/lib_sprite/init_portal_sprite.cpp\
		src/lib_jam/lib_sprite/case_came.cpp\
		src/lib_jam/lib_sprite/handle_frame_portal.cpp\
		src/lib_jam/lib_music/init_music.cpp\
		main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = prog

CXX = g++

##CXXFLAGS =  -Wall -Wextra -Werror
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) *~

fclean: clean
	rm -f $(NAME)

re: fclean all
