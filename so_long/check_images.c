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

int	check_animations(void);
int	check_animations1(void);

int	check_images(void)
{
	int		fd;

	fd = open("textures/coin.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/door.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/enemy_left.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/enemy_right.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/ground.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_images0(void)
{
	int		fd;

	fd = open("textures/lost.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/player_left.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/player.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/playerindoor.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/wall.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_images1(void)
{
	int		fd;

	fd = open("textures/wall01.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	fd = open("textures/won.xpm", O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_numbers(void)
{
	char	*template;
	int		i;
	int		fd;
	char	*filename;

	i = 0;
	template = "textures/numbers/0.xpm";
	filename = ft_strdup(template);
	while (i <= 9)
	{
		filename[17] = '0' + i;
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
		i++;
	}
	free(filename);
	return (0);
}

void	check_all_images(void)
{
	if (check_images() || check_images0() || check_images1()
		|| check_numbers() || check_animations1() || check_animations())
	{
		perror("\e[31mError\nImage not found");
		exit(1);
	}
}
