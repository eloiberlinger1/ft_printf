NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Wall -Werror
DFLAGS = -g
C_FILES =  ft_printf.c ft_utils.c ft_printhex.c ft_printchar.c ft_printnbr.c

O_FILES = $(C_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT_L = -L$(LIBFT_DIR) -lft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR) all
	make -C $(LIBFT_DIR) bonus

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
	make -C $(LIBFT_DIR) CFLAGS="$(DFLAGS)" all
	$(MAKE) CFLAGS="$(DFLAGS)" $(NAME)

.PHONY : all clean fclean re
