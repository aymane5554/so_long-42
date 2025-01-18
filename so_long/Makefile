CC = cc 
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SHARED_SRCS = get_next_line.c get_next_line_utils.c tests.c path_to_coins.c utils.c
SHARED_OBJS = $(SHARED_SRCS:%.c=%.o)
SOURCES = main.c movement.c ending.c init.c display_moves.c errors.c 
OBJS = $(SOURCES:%.c=%.o)
BONUS_SOURCES = bonus/main_bonus.c bonus/movement_bonus.c bonus/enemy_bonus.c bonus/ending_bonus.c bonus/counter_bonus.c bonus/animation_bonus.c bonus/init_bonus.c bonus/display_moves_bonus.c bonus/errors_bonus.c 
BONUS_OBJS = $(BONUS_SOURCES:%_bonus.c=%_bonus.o)
all : $(NAME)

$(NAME): $(OBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(SHARED_OBJS) -L mlx -lmlx -lXext -lX11 -o $(NAME)

bonus: so_long_bonus

so_long_bonus : $(BONUS_OBJS) $(SHARED_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(SHARED_OBJS) -L mlx -lmlx -lXext -lX11 -lm -o so_long_bonus

get_next_line%.o : get_next_line%.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/header_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(SHARED_OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME) so_long_bonus

re : fclean all