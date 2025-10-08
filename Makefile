# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 02:30:07 by pabartoc          #+#    #+#              #
#    Updated: 2025/10/08 20:20:11 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE =	ft_printf.c \

OBJECTS = $(SOURCE:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Rule for compiling .c \ files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Default rule
all: $(NAME)

# Clean object files
clean:
	@rm -f $(OBJECTS)

# Clean everything (object files and library)
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re