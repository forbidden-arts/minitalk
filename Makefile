# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 07:10:18 by dpalmer           #+#    #+#              #
#    Updated: 2022/12/15 12:20:29 by dpalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INCOMPLETE - FIX LATER.

# Variables

NAME		=	client
NAMESV		=	server
INCLUDE		=	-I include
LIBFT		=	libft
SRC_DIR		=	src/
OBJ_DIR		=	objs/
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
AR			=	ar rcs

# Colors

C_RESET = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
B_MAGENTA = \033[1;35m
CYAN = \033[0;96m

#Sources

SRC_FILES	=	client	\
				server


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@mv $(LIBFT)/libft.a ./libft.a
# 			@mv libft.a $(NAME)
#			@$(AR) $(NAME) $(OBJ)
			@$(CC) $(CFLAGS) $(INCLUDE) libft.a $(OBJ_DIR)client.o -o client
			@echo "\n$(B_MAGENTA)MINITALK CLIENT COMPILED SUCCESSFULLY$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) libft.a $(OBJ_DIR)server.o -o server
			@echo "\n$(B_MAGENTA)MINITALK SERVER COMPILED SUCCESSFULLY$(C_RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(GREEN)Compiling: $(YELLOW)$<$(C_RESET)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
#			@echo "$(B_MAGENTA)FT_PRINTF COMPILED$(C_RESET)"

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@echo "$(BLUE)OBJECT FILES DELETED$(C_RESET)"

fclean:		clean
			@rm -f $(NAME) $(NAMESV)
			@echo "$(CYAN)EXECUTABLE FILES DELETED$(C_RESET)"
			@rm -f libft.a
			@echo "$(CYAN)LIBFT LIBRARY DELETED$(C_RESET)"

re:			fclean all
