# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 18:43:47 by ncruz-ne          #+#    #+#              #
#    Updated: 2026/05/20 17:45:08 by ncruz-ne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I. -w

OBJS = ft_printf.o ft_printf_hex.o ft_printf_ptr.o ft_putnbr_fd_len.o \
	ft_putchar_fd_len.o ft_putstr_fd_len.o ft_nlen.o \
	ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	ft_isdigit.o ft_isprint.o ft_isspace.o ft_itoa.o ft_memchr.o ft_memcmp.o \
	ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o \
	ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o \
	ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o \
	ft_strncmp.o ft_strcmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o \
	ft_tolower.o ft_toupper.o ft_lstadd_back.o ft_lstadd_front.o \
	ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstlast.o ft_lstmap.o \
	ft_lstnew.o ft_lstsize.o \
	get_next_line.o get_next_line_utils.o \

all : $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

MAIN_OBJS = TESTS/main.o

EXEC = TESTS/main

$(EXEC): $(MAIN_OBJS) $(NAME)
	$(CC) $(CFLAGS) -g -Wno-format -Wno-format-overflow $(MAIN_OBJS) $(NAME) -o $(EXEC)

run: $(EXEC)
	./$(EXEC)

clean :
	@-rm -f $(OBJS) $(MAIN_OBJS)

fclean : clean
	@-rm -f $(NAME) $(EXEC)

re : fclean all

.PHONY : all clean fclean re run
