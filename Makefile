NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
INCLUDE = include
SRCDIR1=src
SRCDIR2=src/libft
SRCS1_NAME = a_minus_b.c printf_d_i_u.c ft_itoa_u.c  printf_p.c ft_printf.c \
init_t_printf_format.c is_conversion_specifier.c itoa_hexa.c print_target.c \
printf_c.c printf_s.c printf_x.c printf_xx.c set_field_width_flag.c \
set_identified_type_conversion_specifier.c set_zero_flag.c write_chars.c \

SRCS2_NAME = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
                ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
                ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
                ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
                ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
                ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
                ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c


OBJS1 = $(SRCS1_NAME:%.c=%.o)
OBJS2 = $(SRCS2_NAME:%.c=%.o)




$(NAME): $(OBJS1) $(OBJS2)
	ar rc $(NAME) $(OBJS1) $(OBJS2)



%.o: $(SRCDIR1)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

%.o: $(SRCDIR2)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

.PHONY: all
all: $(NAME) 

.PHONY: bonus
bonus: all
.PHONY: clean
clean:
	rm -f $(OBJS1) $(OBJS2)

.PHONY: fclean
fclean: clean
	rm -f $(NAME) 

.PHONY: re
re: fclean all

