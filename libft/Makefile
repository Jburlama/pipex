# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jburlama <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 19:20:36 by jburlama          #+#    #+#              #
#    Updated: 2024/02/18 16:00:58 by jburlama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		 ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		 ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strcut.c  ft_strlcut.c
FT_PRINTF_SRC = ft_printf.c print_char.c print_string.c \
				print_ptr.c print_decimal.c print_unsigned_dec.c\
				print_decimal2.c print_hexa.c
GET_NEXT_LINE_SRC = get_next_line.c get_next_line_utils.c
OBJS = ${CFILES:.c=.o} 
FT_PRINTF_OBJS = ${FT_PRINTF_SRC:.c=.o} 
GET_NEXT_LINE_OBJS = ${GET_NEXT_LINE_SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) ${FT_PRINTF_OBJS} ${GET_NEXT_LINE_OBJS}
	@$(AR) ${NAME} $^

${OBJS}: ${CFILES}
	@$(CC) $(CFLAGS) -c $^

${FT_PRINTF_OBJS}: ${FT_PRINTF_SRC}
	@$(CC) $(CFLAGS) -c $^

${GET_NEXT_LINE_OBJS}: ${GET_NEXT_LINE_SRC}
	@$(CC) $(CFLAGS) -c $^

clean:
	@$(RM) ${OBJS} ${FT_PRINTF_OBJS} ${GET_NEXT_LINE_OBJS}

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
