# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrigarc <adrigarc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 20:07:44 by adrigarc          #+#    #+#              #
#    Updated: 2023/09/06 15:25:49 by adrigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------------------------#
#                   PRINTF MAKEFILE                  #
#---------------------------------------------------#

# Name of the output library
NAME = libftprintf.a

# Define some color codes for pretty printing
RED = \033[91m
YELLOW = \033[93m
WHITE = \033[97m
GREEN = \033[92m
DEF_CL = \033[m
CYAN = \033[96m

#---------------------------------------------------#
#                   COMPILER SETTINGS               #
#---------------------------------------------------#

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -I

# Command to remove files
RM = rm -f

# Command to run norminette
NORM = norminette -R CheckForbiddenSourceHeader .

#---------------------------------------------------#
#                   SOURCE FILES                    #
#---------------------------------------------------#

# Header file
HEADER = ft_printf.h

# Source files
SRC    = ft_printf.c ft_utils.c ft_printf_s.c ft_printf_di.c ft_printf_u.c ft_printf_x.c \
ft_printf_5.c ft_printf_c.c ft_printf_p.c

# Object files generated from source files
OBJ    = $(SRC:.c=.o)

# Dependencies generated from source files
DEPS   = $(SRC:.c=.d)

#---------------------------------------------------#
#                   OBJECT FILES                    #
#---------------------------------------------------#

# Rule to generate an object file from a C source file
%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -MMD -c $< -o $@
	@echo "$(CYAN)Compiling: $(CYAN)$<$(DEF_CL) $(GREEN)[OK]$(DEF_CL)"

#---------------------------------------------------#
#                   MAIN TARGET                     #
#---------------------------------------------------#

# Default rule to build the static library
all: $(NAME)

# Include dependencies for all source files
-include $(DEPS)

# Rule to build the static library
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library $(GREEN)$(NAME)$(DEF_CL) $(GREEN)[OK]$(DEF_CL)"

#---------------------------------------------------#
#                    CLEANING                       #
#---------------------------------------------------#

# Rule to clean up object files and dependencies
clean:
	@$(RM) $(OBJ)
	@echo "$(CYAN)	Deleted objects: $(RED)$(OBJ) $(DEF_CL)"
	@$(RM) $(DEPS)
	@echo "$(CYAN)	Deleted dependencies: $(RED)$(DEPS) $(DEF_CL)"

# Rule to remove the compiled library file and cleaned object files
fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)	DELETED: $(RED)$(NAME)$(DEF_CL)"

#---------------------------------------------------#
#               ADDITIONAL TARGET                   #
#---------------------------------------------------#

# Rule to completely rebuild the program from scratch
re: fclean all

# Rule to apply and print norminette
norm:
	@echo "$(YELLOW)Norminette says:$(DEF_CL)"
	@$(NORM)

# Rule to tell make that the listed targets do not correspond to actual files.
.PHONY: all clean fclean re norms