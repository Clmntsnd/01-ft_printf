# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csenand <csenand@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 11:43:00 by csenand           #+#    #+#              #
#    Updated: 2022/11/14 15:14:36 by csenand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#			***			GENERAL SYNTAX				***
# 
#	The general syntax of a Makefile rule is as follows:
#
#		target : dependency1 dependency2 ...
#			[TAB] action1
#			[TAB] action2
#			...
#
#			***			SPECIAL CHARACTERS			***
#
#	Inside actions we can use:
# 		$@ to represent the full target name of the current target
# 		$? returns the dependencies that are newer than the current target
# 		$* returns the text that corresponds to % in the target
# 		$< returns the name of the first dependency
# 		$^ returns the names of all the dependencies with space as the delimiter
#
#	** SOURCE : https://github.com/amjadmajid/Makefile	**

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -I.

NAME		=	libftprintf.a

SRC			= 	ft_len_ft.c ft_print_ft.c ft_printf.c ft_put_ft.c \

OBJ			= $(SRC:.c=.o)

RM			= rm -rf

AR			= ar rcs 

# compile library
$(NAME): $(OBJ)
	$(AR) $@ $^
	@echo "Libftprintf Done !"

# create all files .o (object) from files .c (source code)
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

# creer "l'executable" 
all : $(NAME)

# Removes objects
clean :
	@echo "Removing $(NAME) objects..."
	$(RM) $(OBJ) $(OBJ_BONUS)
	@echo "$(NAME) objects successfully deleted."

# Removes objects (with clean) and executable
fclean : clean
	@echo "Removing $(NAME) program..."
	$(RM) $(NAME)
	@echo "Executable(s) and archive(s) successfully deleted."

# Removes objects and executable then remakes all
re : fclean all