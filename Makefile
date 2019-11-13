# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayache <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 14:14:36 by jayache           #+#    #+#              #
#    Updated: 2019/11/13 11:34:24 by jayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN = main.c
S = help.c helper_update_screen.c hooks.c draw.c handle_colors.c ft_draw_point.c fractals.c
MO = $(MAIN:.c=.o)
O = $(S:.c=.o)
L = libft.a
I = fractol.h

TARGET = fractol 
FLAGS = -Wextra -Wall -g3 -O3 #-fsanitize=address
LINKER = -lmlx -lm -framework OpenGL -framework AppKit

LIBDIR = libft/
OBJDIR = obj/
SRCDIR = src/
INCDIR = inc/

OBJ := $(addprefix $(OBJDIR), $(O))
MOBJ := $(addprefix $(OBJDIR), $(MO))
SRC := $(addprefix $(SRCDIR), $(S))
LIB := $(addprefix $(LIBDIR), $(L))
INC := $(addprefix $(INCDIR), $(I))
DEP = $(OBJ:%.o=%.d) $(MOBJ:%.o=%.d)

all:
	@mkdir -p $(OBJDIR)	
	@make -C $(LIBDIR) 
	@make $(TARGET)

errorlibft:
	@echo "The libft recipe failed, you stoopid."
	@exit

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@clang -MMD -c $(FLAGS) $< -I $(INCDIR) -o $@ 
	@echo "Creating $@"

$(TARGET): $(LIB) $(OBJ) $(MOBJ) $(INC)
	clang $(OBJ) $(MOBJ) $(FLAGS) $(LIB) -o $(TARGET) $(LINKER)

$(LIB):
	make -C $(LIBDIR)

clean:
	@rm -rf $(OBJ) $(UOBJ) $(MOBJ) $(DEP)
	@make clean -C $(LIBDIR) 

fclean: clean
	@rm -rf $(UTARGET) $(TARGET)
	@make fclean -C $(LIBDIR)

re: fclean all

-include $(DEP)
