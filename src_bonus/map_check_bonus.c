/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:48:43 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/01 10:18:30 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	check_map_name(char *map_name)
{
	if (ft_strncmp(map_name + ft_strlen(map_name) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nProblem with map extension!\n");
		return (-1);
	}
	return (0);
}

int	check_for_exit_and_player(t_game *game)
{
	int	x;
	int	y;
	int	exit;
	int	player;

	y = 0;
	exit = 0;
	player = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] == 'E')
				exit++;
			if (game->map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (exit != 1 || player != 1)
		return (-1);
	return (0);
}

int	check_for_collect(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] == 'C')
				game->collect += 1;
			x++;
		}
		y++;
	}
	if (game->collect < 1)
		return (-1);
	return (0);
}

int	check_if_map_is_rectangle(t_game *game)
{
	int	y;
	int	columns_base;

	y = 0;
	while (game->rows > y)
	{
		columns_base = map_columns_len (game->map[y]);
		if (game->columns != columns_base)
			return (-1);
		y++;
	}
	return (0);
}

int	map_check_validation(t_game *game)
{
	if (check_for_exit_and_player(game) == -1)
	{
		ft_printf ("Error\nProblem with Exit or Player!\n");
		return (-1);
	}
	if (check_for_collect (game) == -1)
	{
		ft_printf("Error\nYour map don't have collectibles\n");
		return (-1);
	}
	if (check_if_map_is_rectangle (game) == -1)
	{
		ft_printf("Error\nYour map is not rectangle!\n");
		return (-1);
	}
	if (check_for_first_and_last_line (game) == -1
		|| check_for_columns_wall(game) == -1)
	{
		ft_printf("Error\nYour map has a problem with the walls!\n");
		return (-1);
	}
	map_path_bonus(game->map_name, game);
	return (0);
}
