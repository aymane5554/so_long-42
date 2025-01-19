/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <ayel-arr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:45:58 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/14 10:26:04 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_close(t_arg *arg)
{
	free_images(arg);
	mlx_destroy_display(arg->game.mlx);
	mlx_destroy_window(arg->game.mlx, arg->game.win);
	free(arg->game.mlx);
	free_map(arg->game.map);
	free(arg->game.width_height);
	arg->game.mlx = NULL;
	arg->game.win = NULL;
	arg->game.width_height = NULL;
	exit(0);
	return (0);
}

int	getkey(int keycode, t_arg *arg)
{
	if (keycode == 65307)
		ft_close(arg);
	else if (keycode == 100)
		moveright(&(arg->game), &(arg->player));
	else if (keycode == 97)
		moveleft(&(arg->game), &(arg->player));
	else if (keycode == 119)
		moveup(&(arg->game), &(arg->player));
	else if (keycode == 115)
		movedown(&(arg->game), &(arg->player));
	return (0);
}

void	secondary_images(t_arg *arg)
{
	int	i;

	arg->player.door_img = mlx_xpm_file_to_image(
			arg->game.mlx, "textures/playerindoor.xpm", &i, &i);
	arg->game.wimg = mlx_xpm_file_to_image(
			arg->game.mlx, "textures/won.xpm", &i, &i);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_player	player;
	t_arg		arg;

	check_all_images();
	map_check(argc, argv);
	game.map = load_map(argv[1]);
	game.width_height = map_dimension(game.map);
	if (game.width_height == NULL)
		return (perror("\e[31mError\nInvalid Map"), 1);
	display_errors(&game, &player);
	game.mlx = mlx_init();
	game_init(&game, &player);
	display_map(&game);
	mlx_put_image_to_window(game.mlx, game.win,
		player.img, player.x * 32, player.y * 32);
	arg.game = game;
	arg.player = player;
	secondary_images(&arg);
	mlx_hook(game.win, 2, 1L << 0, getkey, &arg);
	mlx_hook(game.win, 17, 0, ft_close, &arg);
	mlx_loop_hook(game.mlx, display_moves, &arg);
	mlx_loop(game.mlx);
}
