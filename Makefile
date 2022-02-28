# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/02/19 20:56:28 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/

INCS = -Iincludes/
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_util_1.c ft_printf_util_2.c ft_printf_util_3.c ft_printf_util_4.c ft_helper_1.c ft_helper_2.c ft_helper_3.c \
extend_format.c extend_format_util_1.c extend_format_util_2.c extend_format_util_3.c extend_format_util_4.c get_format.c get_format_util_1.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	ar -rcs $@ $^
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@
clean:
	$(RM) $(OBJ_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
