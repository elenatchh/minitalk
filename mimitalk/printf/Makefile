# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 10:37:46 by elefonta          #+#    #+#              #
#    Updated: 2024/02/13 13:59:30 by elefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

PRINTF_H = ft_printf.h

SRCS = ft_printf.c ft_printf_format.c ft_outils.c
OBJECTS = $(SRCS:%.c=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar r $(NAME) $(OBJECTS)
	@echo Building printf
	

%.o: %.c $(PRINTF_H)
	@echo Compiling $<
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo Cleaning up object files
	@rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	@echo Cleaning up printf
	@rm -f $(NAME)

.PHONY: re
re: fclean all
