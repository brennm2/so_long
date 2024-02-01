/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:34:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/01/31 13:32:41 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	check_for_columns_wall(t_game *game)
{
	int	y;
	int	x;
	int	columns;

	columns = game->columns - 1;
	y = 1;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][0] != '1')
				return (-1);
			if (game->map[y][columns] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_for_first_and_last_line(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->rows - 1;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' && game->map[0][x] != '\n'
			&& game->map[0][x] != '\0')
			return (-1);
		x++;
	}
	x = 0;
	while (game->map[y][x])
	{
		if (game->map[y][x] != '1' &&
			game->map[y][x] != '\n'
			&& game->map[y][x] != '\0')
			return (-1);
		x++;
	}
	return (0);
}

int	check_map_characters(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] != 'C' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'P' && game->map[y][x] != '1' &&
				game->map[y][x] != '0' && game->map[y][x] != 'X'
				&& game->map[y][x] != '\0' && game->map[y][x] != '\n')
			{
				ft_printf("Error\nYou have an invalid character in the map!\n");
				return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
