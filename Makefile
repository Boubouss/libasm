NAME    = libasm.a

NASM    = nasm
NFLAGS  = -f elf64

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = src/ft_strlen.s \
          src/ft_strcpy.s \
          src/ft_strcmp.s \
          src/ft_strdup.s \
          src/ft_write.s \
          src/ft_read.s

OBJS    = $(SRCS:.s=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.s
	$(NASM) $(NFLAGS) $< -o $@

tests: $(NAME)
	$(CC) $(CFLAGS) tests/main.c -L. -lasm -I include -o tests_exe

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) tests_exe test_file.txt

re: fclean all

.PHONY: all clean fclean re tests
