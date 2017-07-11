# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 00:20:35 by rchoquer          #+#    #+#              #
#    Updated: 2017/07/11 07:43:35 by rchoquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_printf.a
PROJECT			=	FT_PRINTF

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRC_NAME		=	core.c	format_parser.c	ft_printf.c	init.c	options.c	type.c \
					numbers.c	strings.c	int_types.c

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	ft_printf.h

SRC_PATH		=	src
OBJ_PATH		=	obj
INC_PATH		=	include

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

.PHONY: clean all re fclean

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo $(PROJECT) "-" "\033[32mBuilt FT_PRINTF\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CPPFLAGS) -o $@ -c $^ $(CFLAGS)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	@/bin/rm -f $(OBJ) 2> /dev/null
	@/bin/rm -Rf $(OBJ_PATH) 2> /dev/null
	@echo $(PROJECT) "-" "\033[33mCleaned up object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) 2> /dev/null
	@echo $(PROJECT) "-" "\033[91mCleaned up compiled files\033[0m"

re: fclean all

norme:
	@echo $(PROJECT) "-" "\033[34mNORME\033[0m"
	@norminette $(SRC)
	@norminette $(INC)