/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:11:26 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/01 10:16:09 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	check_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_position.x = x;
				game->player_position.y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_cloaker_position(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (game->rows > y)
	{
		x = 0;
		while (game->columns > x)
		{
			if (game->map[y][x] == 'X')
			{
				ft_printf("CHECK CLOAKER POSITION! Y: %d\n", y);
				ft_printf("CHECK CLOAKER POSITION! X: %d\n", x);
				game->cloaker_position[i].x = x;
				game->cloaker_position[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	copy_map(char *map_name, t_game *game)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nProblem with the map file!");
		return ;
	}
	game->map_copy = malloc(sizeof(char *) * (game->rows));
	if (!game->map_copy)
		return ;
	while (i < game->rows)
	{
		game->map_copy[i] = get_next_line(fd);
		i++;
	}
	close (fd);
}

int	flood_fill(char **map_copy, int y, int x, t_game *game)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return (0);
	if (map_copy[y][x] == 'C')
		game->collect_check++;
	if (map_copy[y][x] == 'E')
		game->exit_check++;
	if (map_copy[y][x] != '1')
		map_copy[y][x] = 'V';
	flood_fill(map_copy, y, x - 1, game);
	flood_fill(map_copy, y, x + 1, game);
	flood_fill(map_copy, y - 1, x, game);
	flood_fill(map_copy, y + 1, x, game);
	if (game->exit_check != 1 || game->collect_check != game->collect)
		return (-1);
	return (0);
}

void	map_path_bonus(char *map_name, t_game *game)
{
	check_player_position(game);
	check_cloaker_position(game);
	copy_map(map_name, game);
	if (flood_fill(game->map_copy, game->player_position.y,
			game->player_position.x, game) == -1)
	{
		ft_printf("Error\nPlayer can't get all coin or get to exit!\n");
		ft_quit_game(game);
	}
	(void)map_name;
}
