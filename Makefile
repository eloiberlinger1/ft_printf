NAME = ft_printf.a
CC = cc
CFLAGS = -Wextra -Wall -Werror

C_FILES =  ft_printf.c ft_utils.c

O_FILES = $(C_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR) all

$(NAME) : $(O_FILES)
	ar rcs $(NAME) $(O_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(O_FILES) $(O_BONUS_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

test:
	make re
	cc main.c -L. ft_printf.a

.PHONY : all clean fclean re
