# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuchikaw <tuchikaw@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 06:05:24 by tuchikaw          #+#    #+#              #
#    Updated: 2024/04/22 04:21:31 by tuchikaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_itoa.c \
					ft_printf.c \
					ft_printf_c.c \
					ft_printf_d.c \
					ft_printf_p.c \
					ft_printf_percent.c \
					ft_printf_s.c \
					ft_printf_u.c \
					ft_printf_x.c


NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re