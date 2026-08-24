NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= ./library/libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= 	srs/parsing/parsing.c srs/parsing/parsing_texture.c srs/parsing/parsing_colors.c srs/parsing/parsing_helper.c srs/parsing/error.c main.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re