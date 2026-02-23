# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 09:11:24 by tlamit            #+#    #+#              #
#    Updated: 2026/02/23 20:15:15 by tlamit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
NAME := philo
HEADER := -I includes
ifndef DEBUG
	CFLAGS := -Wall -Wextra -Werror -g $(HEADER)
else
	CFLAGS := -g $(HEADER)
endif

SRCS_DIR := src
UTILS_DIR := $(SRCS_DIR)/utils
PHILOS_DIR := $(SRCS_DIR)/philos

SRCS_PHILOS := 	$(SRCS_PHILOS)/philo_heart.c \
				$(SRCS_PHILOS)/setup_philos_forks.c \
				$(SRCS_PHILOS)/setup_philos_mutes.c

SRCS_UTILS :=	$(UTILS_DIR)/ft_atoi.c \
				$(UTILS_DIR)/check_args.c \
				$(UTILS_DIR)/printer.c

SRCS :=	$(SRCS_UTILS) \
		philo.c
OBJS := $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -pthread

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 