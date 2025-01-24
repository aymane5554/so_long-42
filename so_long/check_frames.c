/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_frames.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:46:46 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/21 20:46:51 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_animations(void)
{
	char	*template;
	int		i;
	int		fd;
	char	*filename;

	i = 0;
	template = "textures/animation/anime0.xpm";
	filename = ft_strdup(template);
	while (i <= 7)
	{
		filename[24] = '0' + i;
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
		i++;
	}
	free(filename);
	return (0);
}

int	check_animations1(void)
{
	char	*template;
	int		i;
	int		fd;
	char	*filename;

	i = 0;
	template = "textures/animation/ranime0.xpm";
	filename = ft_strdup(template);
	while (i <= 7)
	{
		filename[25] = '0' + i;
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
		i++;
	}
	free(filename);
	return (0);
}
