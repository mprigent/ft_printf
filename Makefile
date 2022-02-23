# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprigent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 10:14:53 by mprigent          #+#    #+#              #
#    Updated: 2021/03/11 15:01:08 by mprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	srcs/ft_printf.c\
		srcs/ft_check_flag.c\
		srcs/ft_check_percent.c\
		srcs/ft_check_type.c\
		srcs/ft_check_width.c\
		srcs/ft_convert_base.c\
        srcs/ft_convert_char.c\
		srcs/ft_convert_int.c\
		srcs/ft_convert_ptr.c\
		srcs/ft_convert_str.c\
		srcs/ft_convert_u.c\
		srcs/ft_convert_xtoa.c\
		srcs/ft_putchar.c\
		srcs/ft_putprecision.c\
		srcs/ft_strtolower.c\
		srcs/ft_utoa.c\

OBJS	=	$(SRCS:.c=.o)

HEADERS	=	includes/ft_printf.h

CC		=	gcc

CFLAGS	= 	-Wall -Werror -Wextra

LIB		=	-L./libft/ -lft

all		:	$(NAME)

$(NAME) :	$(OBJS)
			$(MAKE) -C ./libft
			cp libft/libft.a ./$(NAME)
			ar rcs $@ $^

bonus	:	${NAME}

.c.o	:
			@${CC} ${CFLAGS} -I ${HEADERS} -o  $@ -c $<

clean	:
			$(MAKE) clean -C ./libft
			rm -f $(OBJS)

fclean	:	clean
			$(MAKE) fclean -C ./libft
			rm -f $(NAME)

re		:	fclean all
