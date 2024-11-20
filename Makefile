# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gangel-a <gangel-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 13:04:19 by gangel-a          #+#    #+#              #
#    Updated: 2024/11/18 13:04:19 by gangel-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = libft
SRC  = $(addprefix src, ft_printf.c ft_printf_utils.c ft_printunbr.c)
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ) $(LIBFT_DIR)/$(LIBFT)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re