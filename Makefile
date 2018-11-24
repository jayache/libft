# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:39:42 by jayache           #+#    #+#              #
#    Updated: 2018/11/24 20:10:40 by jayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strnlen.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strdel.c \
	  ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strsub.c \
	  ft_strtrim.c ft_strjoin.c ft_cntspback.c ft_cntspfront.c ft_strsplit.c

MEM = ft_memccpy.c ft_memmove.c ft_memset.c ft_memcpy.c ft_memchr.c \
	  ft_memcmp.c ft_memdel.c ft_memalloc.c ft_bzero.c

PUT = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c

IS = ft_isalpha.c ft_iswhitespace.c ft_islower.c ft_isupper.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isprint.c
TEST = test
NAME = libft.a

DRAW = ft_draw_rect.c
P1 = $(MEM) $(STR) $(IS) ft_toupper.c ft_tolower.c  ft_atoi.c \
	 ft_abs.c ft_sign.c ft_itoa.c
P2 = $(PUT) 
P3 = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 
SRCS = $(P1) $(P2) $(P3) $(DRAW) 
INCLUDES = /usr/local/include
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wextra -Wall
COUNTER = 
NB = $(words $(SRCS))
plus = x $1
all:
	@echo "$(words $(COUNTER)) / $(NB)\c"
	#$(eval NB = $(shell make $(NAME) -n | wc -l | sed s/$$/"- 7) \/ 9)\+1"/ | sed s/^/'(('/ | bc ))
	@make $(NAME) || make error

error:
	@echo "\033[31mThe Makefile failed to make !"

%.o: %.c
	@if [ "$*" = "ft_strlen" ]; then echo "\n\033[38mCOMPILING STRING FUNCTIONS"; fi
	@if [ "$*" = "ft_memccpy" ]; then echo "\n\033[32mCOMPILING MEM FUNCTIONS..."; fi
	@if [ "$*" = "ft_isalpha" ]; then echo "\n\033[33mCOMPILING EVALUATION FUNCTIONS..."; fi
	@if [ "$*" = "ft_putchar" ]; then echo "\n\033[34mCOMPILING PRINT FUNCTIONS..."; fi
	@if [ "$*" = "ft_lstnew" ]; then echo "\n\033[35mCOMPILING LIST FUNCTIONS..."; fi
	@if [ "$*" = "ft_draw_rect" ]; then echo "\n\033[36mCOMPILING DRAWING FUNCTIONS..."; fi
	@if [ "$*" = "ft_atoi" ]; then echo "\n\033[37mCOMPILING MATH FUNCTIONS..."; fi
	@gcc -Werror -Wextra -Wall -c $<
	$(eval COUNTER += x)
	@echo "\b\b\b\b\b\b\b$(words $(COUNTER)) / $(NB)\c"

	
$(NAME): $(OBJS)
	@echo "\n\033[90mLinking library..."
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[1mDONE!"

clean:
	@rm -rf *.o
	@rm -rf *.gch

fclean: clean
	@rm -rf $(NAME)

re: fclean all
