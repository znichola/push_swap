# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 07:44:20 by znichola          #+#    #+#              #
#    Updated: 2022/12/17 20:42:07 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

FILES	=	main                     stack_ops__1 \
			process_inputdata        stack_ops__2 \
			       util   merg   quick_back3   \
			 stack_ops__0      debug    util3    \
			init quicksort basic_sort util2 process_inputdata2
SRC		=	$(addsuffix .c, $(FILES))
OBJ		=	$(SRC:.c=.o)

# INCLUDE	=	push_swap.h

CC 		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
CFLAGS	=	-g3 -fsanitize=address
# CFLAGS		= -g3
RM		=	rm -f

INCLUDE	=	push_swap.h \
			libft/libft.h \
			libft/printf/ft_printf.h \
			libft/get_next_line/get_next_line.h
INC_PAR	=	$(addprefix -I, $(INCLUDE))

# submodule
# libft
LIB_DIR	=	libft
LIB_N	=	libft.a
LIB		=	$(LIB_DIR)/$(LIB_N)


# .c.o :
#		 $(CC) $(CFLAGS) -I${INCLUDE} -c $< -o $(@)

.c.o :
		$(CC) $(CFLAGS) -c $< -o $(@)

all : $(NAME)

$(NAME) : $(LIB) $(OBJ) #$(INCLUDE)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC_PAR) -L$(LIB_DIR) -lft

# $(NAME) : $(LIB) $(PUSH) $(OBJ)
# 		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC_PAR) -L$(LIB_DIR) -lft


bonus : checker
	$(MAKE) -C checker 

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
#	$(MAKE) -C 

re : fclean all bonus

# libft
$(LIB):
		$(MAKE) -C $(LIB_DIR) $(LIB_N)
		cp $(LIB) $(NAME)

.PHONY : all re clean fclean