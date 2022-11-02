# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:01:01 by ebarguil          #+#    #+#              #
#    Updated: 2022/11/02 20:04:10 by ebarguil         ###   ########.fr        #
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
vpath %.c srcs/parsing

SRC		=	srcs/main.c \
			srcs/parsing/ft_check_name.c \
			srcs/parsing/ft_fill_col.c \
			srcs/parsing/ft_isdigit_cub.c \
			srcs/parsing/ft_parsing.c \
			srcs/parsing/ft_read_data.c \
			srcs/parsing/ft_save_elems.c \
			srcs/parsing/ft_save_map.c \
			srcs/parsing/ft_verify_close_map.c \

OBJ		=	$(SRC:srcs/%.c=objs/%.o)
DEP		=	$(SRC:srcs/%.c=objs/%.d)

all			:	libft obj $(NAME)

libft		:
				$(MAKE) -C Libft

-include $(DEP)

$(NAME)		:	$(OBJ) ./Libft/libft.a
				$(C) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

obj			:
				@if [ ! -d "./objs" ]; then\
					echo "mkdir -p objs";\
					mkdir -p objs;\
				fi
				@if [ ! -d "./objs/parsing" ]; then\
					echo "mkdir -p objs/parsing";\
					mkdir -p objs/parsing;\
				fi
				@echo ""

objs/%.o	:	%.c
				$(C) -o $@ -c $< $(CFLAGS) $(CDEP)

clean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs/parsing
				$(RM) objs
				make -C Libft clean

fclean		:
				$(RM) $(OBJ)
				$(RM) $(DEP)
				$(RM) objs/parsing
				$(RM) objs
				$(RM) $(NAME)
				make -C Libft fclean

fsa			:	fclean obj $(OBJ)
				make -C Libft
				$(C) $(CFLAGS) $(CFA) -o $(NAME) $(SRC) $(LIB)

re			:	fclean all

.PHONY		:	all clean fclean re