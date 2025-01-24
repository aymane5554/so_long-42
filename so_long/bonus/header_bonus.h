/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <ayel-arr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:45:49 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/09 10:23:15 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "../get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	void	*img;
	void	*left_img;
	void	*door_img;
	void	**animations;
	void	**rev_animations;
	int		coins;
	char	state;
}	t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	char	velocity;
}	t_enemy;

typedef struct s_game
{
	int		*width_height;
	void	*mlx;
	void	*win;
	int		coins;
	char	**map;
	void	**images;
	t_enemy	*enemies;
	int		number_of_enemies;
	void	*wimg;
	void	*limg;
	void	*e_img_r;
	void	*e_img_l;
}	t_game;

typedef struct s_arg
{
	t_game		game;
	t_player	player;
}	t_arg;

char	*ft_strdup(char *src);
int		*animate_r(t_game game, t_player player);
int		*animate_l(t_game game, t_player player);
int		*animate_u(t_game game, t_player player);
int		*animate_d(t_game game, t_player player);
void	dislay_numbers(t_game game, int moves);
int		find_coins(int x, int y, char **map, int *wh);
void	moveup(t_game game, t_player *player);
void	display_errors(t_game *game, t_player *player);
void	movedown(t_game game, t_player *player);
int		display_moves(t_arg *arg);
void	moveleft(t_game game, t_player *player);
void	moveright(t_game game, t_player *player);
int		map_check(int argc, char **argv);
int		map_horizontal_borders(t_game game);
int		map_vertical_borders(t_game game);
char	*ft_itoa(int n);
char	**load_map(char *file);
int		*map_dimension(char **map);
int		game_init(t_game	*game, t_player *player);
void	display_map(t_game *game);
void	end(t_player *player, t_game game, int x, int y);
void	free_animation_images(t_arg *arg);
void	free_map(char	**map);
void	free_images(t_arg *arg);
int		file_line(char *file);
int		count_enemies(t_game *game);
void	init_enemy_images(t_game	*game);
void	move_enemies(t_game *game);
int		ft_close(t_arg *arg);
char	**mapdup(t_game *game);
void	check_all_images(void);

#endif
