# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/11 17:16:04 by tlamit            #+#    #+#              #
#    Updated: 2026/02/11 19:04:45 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo

CC := cc

SRCS_DIR := src

UTILS_DIR := $(SRCS_DIR)/utils
UTILS_SRCS := $(UTILS_DIR)/utils.c 

SRCS := philo.c \
		$(UTILS_SRCS)

OBJS := $(SRCS:.c=.o)

HEADER := -I includes
CFLAGS := -Wall -Wextra -Werror -g $(HEADER)


all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
