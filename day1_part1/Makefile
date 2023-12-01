NAME = advent 
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 
RM = rm -rf
LIBFT = libft/libft.a
LIBFT_DIR = libft/
SRCS = main.c 
SRCS_DIR = srcs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR = objs/

all: $(NAME)

$(NAME): $(OBJS_DIR) $(LIBFT) $(OBJS)
	cc $(CFLAGS)  -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean	
	$(MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader headers/*.h srcs/*.c
