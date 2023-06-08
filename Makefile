# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 23:26:37 by anunes-c          #+#    #+#              #
#    Updated: 2023/06/08 17:07:45 by anunes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD

AR = ar
ARFLAGS = rc

RM = rm -f

SRCS = ft_printf.c ft_putchar_ret.c ft_putstr_ret.c ft_itoa_hex.c \
	   ft_utoa_base.c ft_lutoa_base.c ft_validate_base.c \
	   ft_freecharptrandreturnzero.c
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LIBFT_DIR = libft/
LIBFT_A = libft/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(LIBFT_A):
	$(LIBFT_MAKE)
	cp $(LIBFT_A) $(NAME)

%.o: %.c %.d
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(LIBFT_MAKE) clean
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(LIBFT_MAKE) fclean
	$(RM) $(NAME)

re: fclean all
	$(LIBFT_MAKE) fclean all

.PHONY: all clean fclean re
