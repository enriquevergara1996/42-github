NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente obligatorios y parte 2:
SRCS = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# Archivos fuente bonus:
BONUS_SRCS = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Compilar objetos
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Regla principal
all: $(NAME)

# Crear la librería estática
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Reglas
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) test_libft

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Reglas para compilar y enlazar el programa de pruebas
test: $(NAME) main.o
	$(CC) $(CFLAGS) main.o -L. -lft -o test_libft

main.o: main.c libft.h
	$(CC) $(CFLAGS) -c main.c -o main.o

.PHONY: all clean fclean re bonus test