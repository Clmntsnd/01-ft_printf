# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loulou <loulou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 11:43:00 by csenand           #+#    #+#              #
#    Updated: 2023/07/14 10:51:38 by loulou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -- Executable's name -- #
NAME		=	ftprintf.a

# -- Compilation Flag -- #
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
# CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -fsanitize=address -g

# -- Remove -- #
RM			=	rm -rf

# -- Archive -- #
AR			=	ar rcs

# -- SRC Files -- #
SRCS_DIR	=	./srcs/
SRCS_LST	= 	ft_len_ft.c ft_print_ft.c ft_printf.c ft_put_ft.c

SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LST))

# -- OBJ Files -- #
OBJS_DIR	=	./obj/
OBJS_LST	=	$(patsubst %.c, %.o, $(SRCS_LST))
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LST))

# -- HEADER Files -- #
HEADER_DIR	=	./include/
HEADER_LST	=	ft_printf.h
HEADER	 	=	$(addprefix $(HEADER_DIR), $(HEADER_LST))

# -- Colors -- #
RESET		= 	\033[0m
RED			= 	\033[0;31m
GREEN		= 	\033[0;32m
YELLOW		= 	\033[0;33m
BLUE		= 	\033[0;34m
PURPLE		= 	\033[0;35m
CYAN		= 	\033[0;36m
ERASE_LINE 	= 	\033[2K\r

# -- Executable's creation -- #
all : dir $(NAME)

# -- Compile library -- #
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "✅ $(GREEN)Ft_printf successfully created.\t\t\t✅$(RESET)"

# -- Create all files .o (object) from files .c (source code) -- #
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@printf "🎛️  $(PURPLE)Compilation of $(YELLOW)$(notdir $<)\r$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# -- Create directory for *.o files -- #
dir:
	@mkdir -p $(OBJS_DIR)

# -- Removes objects -- #
clean :
	@printf "💥 $(RED)Removing $(NAME)'s objects... $(RESET)\t\t\t💥\n"
	@$(RM) $(OBJS_DIR)
	@printf "🗑️  $(CYAN)ft_printf's object successfully deleted.$(RESET)\t\t🗑️\n"

# -- Removes objects (with clean) and executable -- #
fclean : clean
	@printf "💥 $(RED)Removing $(NAME)'s executable... $(RESET)\t\t\t💥\n"
	@$(RM) $(NAME)
	@printf "🗑️  $(CYAN)Executable(s) and archive(s) successfully deleted.$(RESET)\t🗑️\n"

# -- Removes objects and executable then remakes all -- #
re : fclean all

# -- Avoid file-target name conflicts -- #
.PHONY: all bonus clean fclean re