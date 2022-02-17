# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/02/17 22:00:59 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
INCS = includes
NAME = libftprintf.a
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^
bonus: $(OBJS_BONUS)
	ar -rcs $(NAME) $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCS) -o $@
clean:
	$(RM) $(OBJS_BONUS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
