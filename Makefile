# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anunes-c <anunesc-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 23:26:37 by anunes-c          #+#    #+#              #
#    Updated: 2023/05/30 00:12:00 by anunes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft/
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(LIBFT_A):
	@$(LIBFT_MAKE)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(LIBFT_MAKE) clean
	@rm -f $(OBJS)

fclean: clean
	@$(LIBFT_MAKE) fclean
	@rm -f $(NAME)

re: fclean all
	@$(LIBFT_MAKE) fclean all

.PHONY: all clean fclean re
