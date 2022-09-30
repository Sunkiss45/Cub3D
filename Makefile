# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:01:01 by ebarguil          #+#    #+#              #
#    Updated: 2022/09/30 16:16:04 by ebarguil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d

INC		=	includes

C		=	clang
CFLAGS	=	-Wall -Wextra -Werror -I $(INC)
CDEP	=	-MMD
CFA		=	-fsanitize=address -g3
RM		=	/usr/bin/rm -rf

LIB		=	-L ./Libft -lft

vpath %.c srcs

SRC		=	srcs/main.c \

OBJ		=	$(SRC:srcs/%.c=objs/%.o)
DEP		=	$(SRC:srcs/%.c=objs/%.d)

all			:	libft obj $(NAME)

libft		:
				$(MAKE) -C Libft

-include $(DEP)

$(NAME)		:	$(OBJ)
				$(C) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

obj			:
				@if [ ! -d "./objs" ]; then\
					echo "mkdir -p objs";\
					mkdir -p objs;\
				fi
				@echo ""

objs/%.o	:	%.c
				$(C) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs
				make -C Libft clean

fclean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs
				$(RM) $(NAME)
				make -C Libft fclean

fsa			:	fclean obj $(OBJ)
				make -C Libft
				$(C) $(CFLAGS) $(CDEP) $(CFA) -o $(NAME) $(SRC) $(LIB)

re			:	fclean all

.PHONY		:	all clean fclean re