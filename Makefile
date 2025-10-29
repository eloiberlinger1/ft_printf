NAME = libftprintf.a
CC = cc
CFLAGS = -Wextra -Wall -Werror
DFLAGS = -g
C_FILES =  ft_printf.c ft_utils.c ft_printhex.c ft_printchar.c ft_printnbr.c

O_FILES = $(C_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT_L = -L$(LIBFT_DIR) -lft
LIBFT_A = $(LIBFT_DIR)/libft.a

# -----------------
# DEFAULT RULES
# -----------------
all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR) all
	make -C $(LIBFT_DIR) bonus

$(NAME) : $(O_FILES)
	ar rcs $(NAME) $(O_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: fclean_all
	@echo "--- compilation DEBUG (-g) ---"
	
	make -C $(LIBFT_DIR) CFLAGS="$(DFLAGS) $(CFLAGS)" all
	make -C $(LIBFT_DIR) CFLAGS="$(DFLAGS) $(CFLAGS)" bonus
	$(MAKE) CFLAGS="$(DFLAGS) $(CFLAGS)" $(NAME)
	$(CC) $(DFLAGS) $(CFLAGS) main.c $(NAME) $(LIBFT_L)

fclean_all: clean
	rm -f $(NAME) $(TEST_EXEC)
	make -C $(LIBFT_DIR) fclean

clean:
	rm -f $(O_FILES) $(O_BONUS_FILES)
	make -C $(LIBFT_DIR) clean

fclean: fclean_all

re: fclean all

.PHONY : all clean fclean re
