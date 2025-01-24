/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <ayel-arr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:45:49 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/09 10:23:15 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	void	*img;
	void	*left_img;
	void	*door_img;
	int		coins;
	char	state;
}	t_player;

typedef struct s_game
{
	int		*width_height;
	void	*mlx;
	void	*win;
	int		coins;
	char	**map;
	void	**images;
	void	*wimg;
}	t_game;

typedef struct s_arg
{
	t_game		game;
	t_player	player;
}	t_arg;

char	*ft_strdup(char *src);
int		find_coins(int x, int y, char **map, int *wh);
void	moveup(t_game *game, t_player *player);
void	display_errors(t_game *game, t_player *player);
void	movedown(t_game *game, t_player *player);
int		display_moves(t_arg *arg);
void	moveleft(t_game *game, t_player *player);
void	moveright(t_game *game, t_player *player);
int		map_check(int argc, char **argv);
int		map_horizontal_borders(t_game game);
int		map_vertical_borders(t_game game);
char	*ft_itoa(int n);
char	**load_map(char *file);
int		*map_dimension(char **map);
int		game_init(t_game	*game, t_player *player);
void	display_map(t_game *game);
void	end(t_player *player, t_game game, int x, int y);
void	free_map(char	**map);
void	free_images(t_arg *arg);
int		file_line(char *file);
int		ft_close(t_arg *arg);
char	**mapdup(t_game *game);
void	check_all_images(void);

#endif
