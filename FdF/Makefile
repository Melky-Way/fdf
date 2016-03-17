#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 18:21:40 by msoudan           #+#    #+#              #
#    Updated: 2016/03/09 19:30:50 by msoudan          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CPATH = srcs
HPATH = includes
LIBPATH = libft

NAME = fdf
LIB = $(LIBPATH)/libft.a

CC = /usr/bin/gcc
RM = /bin/rm
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_matrixoperations.c \
	ft_pix_put_img.c \
	ft_transformmap.c \
	ft_getgradient.c \
	ft_getmap.c \
	ft_applymatrix.c \
	ft_draw.c \
	ft_scaleandcenter.c \
	ft_fdfclean.c \
	main.c

CFILES = $(patsubst %,$(CPATH)/%,$(SRC))
OFILES = $(patsubst %.c,%.o,$(CFILES))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	@make -C $(LIBPATH)
	@$(CC) -L $(LIBPATH) -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit $^ -o $@
	@clear
	@echo "\033[36m\\o/ Finished ! \\o/\033[0m"

%.o: %.c
	@$(CC) -I $(HPATH) -I $(LIBPATH)/$(HPATH) $(CFLAGS) -c $^ -o $@

clean:
	@make -C $(LIBPATH) clean
	@$(RM) -f $(OFILES)

fclean: clean
	@make -C $(LIBPATH) fclean
	@$(RM) -f $(NAME)

re: fclean all
