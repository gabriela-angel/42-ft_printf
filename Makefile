# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:04:19 by gangel-a          #+#    #+#              #
#    Updated: 2024/11/21 15:49:39 by gangel-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a

LIBFT_DIR = libft/
SRC_DIR = src/
OBJ_DIR = obj/

SRC  = ft_printf.c ft_printf_utils.c ft_printunbr.c
OBJ = $(addprefix $(OBJ_DIR), $(SRC:%.c=%.o))

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo "Including library: $(LIBFT_DIR)$(LIBFT)"
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@
	@echo "object directory created"

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re