# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquer <rchoquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 00:20:35 by rchoquer          #+#    #+#              #
#    Updated: 2017/07/12 00:25:40 by rchoquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
PROJECT			=	FT_PRINTF

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRC_NAME		=	core.c				format_parser.c		ft_printf.c		\
					init.c				options.c			output_number.c	\
					output_string.c		int_types.c			string_types.c	\
					special_types.c		data_string.c		utils.c
					

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	ft_printf.h

SRC_PATH		=	srcs
OBJ_PATH		=	objs
INC_PATH		=	includes

SRC				=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ				=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC				=	$(addprefix $(INC_PATH)/,$(INC_NAME))

.PHONY: clean all re fclean

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@ar rc $@ $(OBJ)
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