# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrosmari <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 20:33:20 by jrosmari          #+#    #+#              #
#    Updated: 2023/01/25 15:23:50 by jrosmari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS=ft_printf.c 

OBJECTS=ft_printf.o 

INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	@cc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)


clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re






