/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-arr <ayel-arr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:47:31 by ayel-arr          #+#    #+#             */
/*   Updated: 2025/01/09 11:39:25 by ayel-arr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	display_moves(t_arg *arg)
{
	char	*moves;
	int		i;

	i = 0;
	moves = ft_itoa(arg->player.moves);
	while (moves[i])
	{
		write(1, moves + i, 1);
		i++;
	}
	write(1, "\n", 1);
	free(moves);
	return (1);
}
