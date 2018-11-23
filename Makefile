# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:39:42 by jayache           #+#    #+#              #
#    Updated: 2018/11/12 13:09:30 by jayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strnlen.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c

STR2 = ft_strdel.c ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c \
	   ft_strmap.c ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strsub.c \
	   ft_strtrim.c ft_strjoin.c ft_cntspback.c ft_cntspfront.c ft_strsplit.c

MEM = ft_memccpy.c ft_memmove.c ft_memset.c ft_memcpy.c ft_memchr.c ft_memcmp.c

MEM2 = ft_memdel.c ft_memalloc.c

PUT = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c

IS = ft_isalpha.c ft_iswhitespace.c ft_islower.c ft_isupper.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isprint.c

NAME = libft.a
P1 = $(MEM) $(STR) $(IS) ft_toupper.c ft_tolower.c  ft_bzero.c ft_atoi.c \
	 ft_abs.c ft_sign.c
P2 = $(MEM2) $(STR2) $(PUT) ft_itoa.c ft_tmalloc.c
P3 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 
SRCS = $(P1) $(P2) $(P3) 
INCLUDES = libft.h
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wextra -Wall
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf *.o
	rm -rf *.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all
