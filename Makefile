# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrielp <gabrielp@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/26 01:16:41 by gabrielp          #+#    #+#              #
#    Updated: 2023/04/26 01:16:43 by gabrielp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_write.c ft_num.c

OBJS = $(SRCS:.c=.o)

CC = @cc

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror
MSG1 = @echo "Compiled 🕺"
MSG2 = @echo "Cleaned 🌚"

ARCHIVE = @ar -rc

RANLIB = @ranlib

all: $(NAME)

$(NAME): $(OBJS)
				$(ARCHIVE) $(NAME) $(OBJS)
				$(RANLIB) $(NAME)
				$(MSG1)

clean:
		$(RM) $(OBJS)
		$(MSG2)

fclean: clean
			$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re