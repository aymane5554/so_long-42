/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <ayel-arr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:46:15 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/01 14:46:58 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_extension(char *filename)
{
	int		i;
	int		ii;
	char	*ext;

	i = 0;
	ii = 0;
	ext = ".ber";
	while (filename[i])
		i++;
	while (filename[i] != '.')
		i--;
	while (filename[i])
	{
		if (filename[i] != ext[ii])
			return (-1);
		i++;
		ii++;
	}
	return (1);
}

int	map_check(int argc, char **argv)
{
	int	fd;

	if (argc == 1 || check_extension(argv[1]) == -1)
	{
		perror("\e[31mError\n./so_long file.ber");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("\e[31mError\n");
		exit(1);
	}
	close(fd);
	return (1);
}

int	map_horizontal_borders(t_game game)
{
	int		i;
	char	*s;

	i = 0;
	s = game.map[0];
	while (i < game.width_height[0])
	{
		if (s[i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	s = game.map[game.width_height[1] - 1];
	while (i < game.width_height[0])
	{
		if (s[i] != '1')
			return (-1);
		i++;
	}
	return (1);
}

int	map_vertical_borders(t_game game)
{
	int		i;

	i = 0;
	while (i < game.width_height[1])
	{
		if (game.map[i][0] != '1' ||
			game.map[i][game.width_height[0] - 1] != '1')
			return (-1);
		i++;
	}
	return (1);
}
