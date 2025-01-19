/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:41:41 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/19 15:41:43 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	check_game_images(void)
{
	if (open("coin.xpm", O_RDONLY) == -1 || open("door.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("enemy_right.xpm", O_RDONLY) == -1
		|| open("enemy_left.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("ground.xpm", O_RDONLY) == -1 || open("lost.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("player_left.xpm", O_RDONLY) == -1
		|| open("player.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("playerindoor.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("wall.xpm", O_RDONLY) == -1 || open("wall01.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("won.xpm", O_RDONLY) == -1)
		return (-1);
	return (1);
}

char	check_number_images(void)
{
	if (open("0.xpm", O_RDONLY) == -1 || open("1.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("2.xpm", O_RDONLY) == -1 || open("3.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("4.xpm", O_RDONLY) == -1 || open("5.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("6.xpm", O_RDONLY) == -1 || open("7.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("8.xpm", O_RDONLY) == -1 || open("9.xpm", O_RDONLY) == -1)
		return (-1);
	return (1);
}

char	check_animation_frames(void)
{
	if (open("anime0.xpm", O_RDONLY) == -1
		|| open("anime1.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("anime2.xpm", O_RDONLY) == -1
		|| open("anime3.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("anime4.xpm", O_RDONLY) == -1
		|| open("anime5.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("anime6.xpm", O_RDONLY) == -1
		|| open("anime7.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("ranime0.xpm", O_RDONLY) == -1
		|| open("ranime1.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("ranime2.xpm", O_RDONLY) == -1
		|| open("ranime3.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("ranime4.xpm", O_RDONLY) == -1
		|| open("ranime5.xpm", O_RDONLY) == -1)
		return (-1);
	if (open("ranime6.xpm", O_RDONLY) == -1
		|| open("ranime7.xpm", O_RDONLY) == -1)
		return (-1);
	return (1);
}

void	check_all_images(void)
{
	if (check_animation_frames() == 1
		&& check_game_images() == 1 && check_number_images() == 1)
		return ;
	perror("\e[31mError\nImage not found");
	exit(1);
	return ;
}
