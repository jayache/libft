# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:39:42 by jayache           #+#    #+#              #
#    Updated: 2019/09/14 18:27:44 by jayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

STR = ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c \
	  ft_strnlen.c ft_strchr.c ft_strrchr.c ft_strdup.c ft_strndup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strdel.c \
	  ft_strnew.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strequ.c ft_strnequ.c ft_strmapi.c ft_strsub.c \
	  ft_strtrim.c ft_strjoin.c ft_cntspback.c ft_cntspfront.c ft_strsplit.c \
	  ft_strpbrk.c ft_stradd.c ft_strfjoin.c ft_str3join.c ft_strins.c \
	  ft_strcut.c ft_striswhitespace.c ft_strisnumeric.c

MEM = ft_memccpy.c ft_memmove.c ft_memset.c ft_memcpy.c ft_memchr.c \
	  ft_memcmp.c ft_memdel.c ft_memalloc.c ft_bzero.c ft_free_2d.c ft_len_2d.c

PUT = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c

IS = ft_isalpha.c ft_iswhitespace.c ft_islower.c ft_isupper.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isprint.c

NAME = libft.a

BASE = $(MEM) $(STR) $(IS) $(PUT) ft_toupper.c ft_tolower.c ft_error.c

LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	  ft_lstmap.c  ft_lst_append.c ft_lstgetbypos.c ft_lstnew_no_copy.c
VECTOR2= ft_vector2.c ft_vector2_normalize.c ft_vector2_magnitude.c \
		 ft_vector2_multiply.c ft_vector2_add.c ft_vector2_angle.c \
		 ft_vector2_rangle.c ft_vector2_dot.c
VECTOR3= ft_vector3.c ft_vector3_normalize.c ft_vector3_magnitude.c \
		 ft_vector3_angle.c ft_vector3_axis.c ft_vector3_cross.c \
		 ft_vector3_dot.c ft_vector3_add.c ft_vector3_sub.c \
		 ft_vector3_multiply.c ft_vector3_opposite.c

VECTOR4= ft_vector4.c ft_vector4_p_matrix.c ft_matrix_to_vector4.c \
		 ft_vector4_from_3.c
MATRIX= ft_matrix.c ft_matrix_product.c ft_matrix_free.c \
		ft_vector4_to_matrix.c ft_vector3_to_matrix.c ft_matrix_identity.c \
		ft_print_matrix.c ft_matrix_translation.c ft_matrix_ry.c \
		ft_matrix_diag_symetrie.c ft_matrix_projection.c
MATH= $(VECTOR2) $(VECTOR3) $(VECTOR4) $(MATRIX) ft_atoi.c ft_abs.c ft_sign.c \
	 ft_itoa_base.c ft_nblen.c ft_itoa.c ft_min.c ft_pow.c 

PRINTF= printf.c printf_args.c printf_args2.c printf_args3.c \
		printf_arg_color.c printf_arg_change.c printf_flags2.c printf_flags.c printf_free.c \
		printf_essentials.c printf_parser.c printf_print_arg.c printf_write.c \
		printf_take_arg.c

DIR= ft_is_dot.c ft_is_hidden.c ft_cnt_type.c ft_is_dir.c ft_exists.c

BTREE= ft_btree_apply_prefix.c ft_btree_apply_defix.c ft_btree_apply_infix.c ft_btree_apply_suffix.c ft_btree_create_node.c \
	   ft_btree_insert_data.c ft_btree_free.c

SRCS = $(BASE) $(LST) $(MATH) $(PRINTF)  get_next_line.c $(DIR) $(BTREE)
INCLUDES = /usr/local/include
OBJS = $(SRCS:.c=.o)
COUNTER= 
NB = $(words $(SRCS))
FLAG = -Wall -Wextra -g3 -O3

define tests
$(if $(filter $(1), ft_strlen), @echo "\n\033[32mCOMPILING STRING FUNCTIONS")
$(if $(filter $(1), ft_memccpy), @echo "\n\033[33mCOMPILING MEM FUNCTIONS")
$(if $(filter $(1), ft_isalpha), @echo "\n\033[34mCOMPILING EVAL FUNCTIONS")
$(if $(filter $(1), ft_putchar), @echo "\n\033[35mCOMPILING PRINT FUNCTIONS")
$(if $(filter $(1), ft_draw_point), @echo "\n\033[36mCOMPILING DRAW FUNCTIONS")
$(if $(filter $(1), ft_vector2), @echo "\n\033[37mCOMPILING MATH FUNCTIONS")
$(if $(filter $(1), ft_lstnew), @echo "\n\033[38mCOMPILING LIST FUNCTIONS")
$(if $(filter $(1), ft_is_dot), @echo "\n\033[38mCOMPILING DIR FUNCTIONS")
$(if $(filter $(1), ft_btree_apply_prefix), @echo "\n\033[32mCOMPILING BTREE FUNCTIONS")
$(if $(filter $(1), printf), @echo "\n\033[38mCOMPILING PRINTF")
endef

all:
	@echo "$(words $(COUNTER)) / $(NB)\c"
	@make $(NAME) || make error

error:
	@echo "\033[31mThe Makefile failed to make ! You failed !"

%.o: %.c
	$(call tests, $*)
	@gcc $(FLAG) -c $<
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
