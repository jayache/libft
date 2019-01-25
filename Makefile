# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:39:42 by jayache           #+#    #+#              #
#    Updated: 2019/01/25 17:15:01 by jayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strnlen.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strndup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strdel.c \
	  ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strsub.c \
	  ft_strtrim.c ft_strjoin.c ft_cntspback.c ft_cntspfront.c ft_strsplit.c \
	  ft_strpbrk.c ft_stradd.c ft_strfjoin.c

MEM = ft_memccpy.c ft_memmove.c ft_memset.c ft_memcpy.c ft_memchr.c \
	  ft_memcmp.c ft_memdel.c ft_memalloc.c ft_bzero.c

PUT = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c

IS = ft_isalpha.c ft_iswhitespace.c ft_islower.c ft_isupper.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isprint.c

NAME = libft.a

BASE = $(MEM) $(STR) $(IS) $(PUT) ft_toupper.c ft_tolower.c

LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c 

VECTOR2= ft_vector2.c ft_vector2_normalize.c ft_vector2_magnitude.c \
		 ft_vector2_multiply.c ft_vector2_add.c ft_vector2_angle.c \
		 ft_vector2_rangle.c ft_vector2_dot.c
VECTOR3= ft_vector3.c ft_vector3_normalize.c ft_vector3_magnitude.c \
		 ft_vector3_angle.c ft_vector3_axis.c ft_vector3_cross.c \
		 ft_vector3_dot.c ft_vector3_add.c ft_vector3_sub.c \
		 ft_vector3_multiply.c

VECTOR4= ft_vector4.c ft_vector4_p_matrix.c ft_matrix_to_vector4.c
MATRIX= ft_matrix.c ft_matrix_product.c ft_matrix_free.c \
		ft_vector4_to_matrix.c ft_vector3_to_matrix.c
MATH= $(VECTOR2) $(VECTOR3) $(VECTOR4) $(MATRIX) ft_atoi.c ft_abs.c ft_sign.c \
	 ft_itoa_base.c ft_nblen.c ft_itoa.c ft_min.c ft_pow.c 
BTREE= ft_btree_create_node.c ft_btree_apply_infix.c ft_btree_apply_sufix.c \
	   ft_btree_level_count.c ft_btree_apply_prefix.c \
	   ft_btree_apply_by_level.c ft_btree_search_item.c ft_btree_insert_data.c
	   
PRINTF= printf.c printf_args.c printf_args2.c printf_args3.c \
		printf_arg_color.c printf_arg_change.c printf_flags2.c printf_flags.c printf_free.c \
		printf_essentials.c printf_parser.c printf_print_arg.c printf_write.c \
		printf_take_arg.c
GRAPH= ft_graph_new.c ft_graph_add_link.c ft_graph_node_new.c ft_graph_add_node.c
DRAW = ft_draw_point.c ft_draw_rect.c ft_draw_lign.c
SRCS = $(BASE) $(LST) $(DRAW) $(GRAPH)  $(MATH) $(PRINTF)  get_next_line.c ft_solve.c
INCLUDES = /usr/local/include
OBJS = $(SRCS:.c=.o)
COUNTER= 
NB = $(words $(SRCS))

define tests
$(if $(filter $(1), ft_strlen), @echo "\n\033[32mCOMPILING STRING FUNCTIONS")
$(if $(filter $(1), ft_memccpy), @echo "\n\033[33mCOMPILING MEM FUNCTIONS")
$(if $(filter $(1), ft_isalpha), @echo "\n\033[34mCOMPILING EVAL FUNCTIONS")
$(if $(filter $(1), ft_putchar), @echo "\n\033[35mCOMPILING PRINT FUNCTIONS")
$(if $(filter $(1), ft_draw_point), @echo "\n\033[36mCOMPILING DRAW FUNCTIONS")
$(if $(filter $(1), ft_vector2), @echo "\n\033[37mCOMPILING MATH FUNCTIONS")
$(if $(filter $(1), ft_lstnew), @echo "\n\033[38mCOMPILING LIST FUNCTIONS")
$(if $(filter $(1), ft_graph_new), @echo "\n\033[42m \033[38mCOMPILING GRAPH FUNCTIONS")
$(if $(filter $(1), ft_btree_create_node), @echo "\n\033[42m \033[33mCOMPILING BTREE FUNCTIONS")
$(if $(filter $(1), printf), @echo "\n\033[42m \033[34mCOMPILING PRINTF")
endef

all:
	@echo "$(words $(COUNTER)) / $(NB)\c"
	@make $(NAME) || make error

error:
	@echo "\033[31mThe Makefile failed to make ! You failed !"

%.o: %.c
	$(call tests, $*)
	@gcc -g3 -Werror -Wextra -Wall -c $<
	$(eval COUNTER += x)
	@echo "\b\b\b\b\b\b\b\b\b\b$(words $(COUNTER)) / $(NB)\c"

	
$(NAME): $(OBJS)
	@echo "\n\033[90mLinking library..."
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[1mDONE!"

clean:
	@echo "\033[35mREMOVING OBJECT FILES."
	@rm -rf *.o
	@rm -rf *.gch

fclean: clean
	@echo "\033[35mREMOVING LIBRARY."
	@rm -rf $(NAME)

re: fclean all
