# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 07:44:20 by znichola          #+#    #+#              #
#    Updated: 2022/11/16 23:44:48 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FILES	=	main              stack_ops_0       stack_ops__1 \
			process_inputdata stack_ops_1       stack_ops__2 \
			recursive_solver  stack_ops_2       util         \
			stack_data        stack_ops__0
SRC		=	$(addsuffix .c, $(FILES))
OBJ		=	$(SRC:.c=.o)

INCLUDE	=	push_swap.h

CC 		=	gcc
# CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	=	-g3
RM		=	rm -f

.c.o :
		$(CC) $(CFLAGS) -I${INCLUDE} -c $< -o $(@)

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I$(INCLUDE)

bonus : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : $(NAME) all re clean fclean bonus