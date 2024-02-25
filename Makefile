# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburlama <jhonas.burlamaqui@gmail.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 23:09:10 by jburlama          #+#    #+#              #
#    Updated: 2024/02/25 17:53:07 by jburlama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus
CC = gcc -Wall -Wextra -Werror
SRC = src/pipex.c src/panic.c src/cmd.c src/path.c
BONUS_SRC = bonus/pipex_bonus.c bonus/panic_bonus.c bonus/path_bonus.c bonus/cmd_bonus.c \
			bonus/pipex_utils_bonus.c
LIBFT = libft/libft.a

all: ${NAME} ${BONUS}

${NAME}: ${SRC} ${LIBFT}
	@${CC} $^ -o $@

${BONUS}: ${BONUS_SRC} ${LIBFT}
	@${CC} $^ -o $@

${LIBFT}:
	@make -C libft

clean:
	@make $@ -C libft

fclean:
	@make $@ -C libft
	@rm -rf ${NAME}
	@rm -rf ${BONUS}

re: fclean ${NAME}
