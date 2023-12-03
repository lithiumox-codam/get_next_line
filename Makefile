# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mdekker <mdekker@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/07 12:57:06 by mdekker       #+#    #+#                  #
#    Updated: 2023/12/03 01:00:45 by lithium       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := gnl.out
SRCS := get_next_line.c get_next_line_utils.c
HEADERS := get_next_line.h libft/includes/libft.h libft/includes/vector.h
OBJS := $(addprefix build/, $(SRCS:.c=.o))
CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
# CFLAGS += -fsanitize=address

all: $(OBJS)

build/%.o: %.c
	@mkdir -p $(@D)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf build

fclean: clean

re: fclean all
