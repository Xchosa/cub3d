CC = cc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS  = -Wall -Wextra -Werror -fsanitize=address
AR = ar
NAME = libft.a

MY_SOURCES = ft_atoi.c	\
			ft_atol.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strstr.c \
			ft_strdup.c \
			ft_substr.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c

MY_SOURCES_B = ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

MY_SOURCES_PF = printf/ft_printf_func.c \
			printf/ft_printf_func2.c \
			printf/ft_printf.c \

MY_SOURCES_GNL = 	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_OBJECTS_B = $(MY_SOURCES_B:.c=.o)
MY_OBJECTS_PF = $(MY_SOURCES_PF:.c=.o)
MY_OBJECTS_GNL = $(MY_SOURCES_GNL:.c=.o)


all: $(NAME)


$(NAME): $(MY_OBJECTS) $(MY_OBJECTS_B) $(MY_OBJECTS_PF) $(MY_OBJECTS_GNL)
	$(AR) -rcs $(NAME) $(MY_OBJECTS) $(MY_OBJECTS_B) $(MY_OBJECTS_PF) $(MY_OBJECTS_GNL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS) $(MY_OBJECTS_B) $(MY_OBJECTS_PF) $(MY_OBJECTS_GNL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
