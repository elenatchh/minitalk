# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elefonta <elefonta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 10:05:09 by elefonta          #+#    #+#              #
#    Updated: 2024/09/09 11:34:20 by elefonta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_client = client
NAME_server = server
NAME_printf = printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINITALK = minitalk.h

SRCS_server = src/server.c 
SRCS_client = src/client.c

OBJECTS_client = $(SRCS_client:%.c=%.o)
OBJECTS_server = $(SRCS_server:%.c=%.o)

.PHONY: all
all: $(NAME_client) $(NAME_server)

$(NAME_client): $(OBJECTS_client)
	make -C printf
	@$(CC) $(CFLAGS) -o $(NAME_client) $(OBJECTS_client) $(NAME_printf)
	@echo "Building client"

$(NAME_server): $(OBJECTS_server)
	@$(CC) $(CFLAGS) -o $(NAME_server) $(OBJECTS_server) $(NAME_printf)
	@echo "Building server"

%.o: %.c $(MINITALK)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning up object files"
	@rm -f $(OBJECTS_client)
	@rm -f $(OBJECTS_server)
	make -C printf clean

.PHONY: fclean
fclean: clean
	@echo "Cleaning up executables"
	@rm -f $(NAME_client)
	@rm -f $(NAME_server)
	@rm -f $(NAME_printf)

.PHONY: re
re: fclean all

