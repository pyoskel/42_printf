# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/05 02:30:07 by pabartoc          #+#    #+#              #
#    Updated: 2025/10/30 07:32:31 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT :

NAME = libftprintf.a
HEADER = ft_printf.h
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCE =	ft_printf.c \
			ft_printf_add_ons.c \

OBJECTS = $(SOURCE:.c=.o)

# Default rule
all: $(NAME)

# Create the static library
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	echo "\033[1;32m ✅ [ft_printf created]\033[0m"
	
# Rule for compiling .c \ files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJECTS)

# Clean everything (object files and library)
fclean: clean
	@rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

# Ansi colors for output

# BLUE   = "\033[38;5;4m"
# GREEN  = "\033[38;5;2m"
# ORG    = "\033[38;5;214m"
# RED    = "\033[38;5;196m"
# RESET  = "\033[0m"