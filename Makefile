# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsergien <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 19:17:56 by tsergien          #+#    #+#              #
#    Updated: 2018/09/13 11:23:50 by tsergien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_FILES = additional.c main.c keys.c mouse.c rgb.c fractal.c complex.c keys2.c threads.c

SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

HEADER = -I /usr/local/include/ -I includes/

FRAME = -L /usr/local/lib/ -lmlx -framework OpenGl -framework AppKit -lm -lpthread

LIB_DIR = libft/

WWW = -Wall -Wextra -Werror

COLOR = \x1b[38;5;213m

RESET_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR)
	@cc $(OBJ) -o $(NAME) $(HEADER) $(FRAME) -L $(LIB_DIR) -lft
	@echo "$(COLOR)***		fractol compiled	***$(RESET_COLOR)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@gcc $(WWW) -o $@ -c $< $(HEADER)

clean:
	@make clean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)***		obj cleaned		***$(RESET_COLOR)"

fclean: clean
	@make fclean -C $(LIB_DIR)
	@rm -f $(NAME)
	@echo "$(COLOR)***		fractol deleted		***$(RESET_COLOR)"

norm:
	@norminette $(SRC) includes/fractol.h

re: fclean all
