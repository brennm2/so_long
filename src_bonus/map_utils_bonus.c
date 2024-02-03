/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:10:15 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/03 10:44:18 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	count_lines(char *map_name)
{
	char	*tmp;
	int		rows;
	int		fd;

	rows = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFailed to open the map!\n");
		return (-1);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		rows++;
		tmp = get_next_line(fd);
	}
	close(fd);
	free (tmp);
	return (rows);
}

void	fill_map(int fd, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
}

int	map_columns_len(char *map_row)
{
	int	i;

	i = 0;
	while (map_row[i] && map_row[i] != '\n' && map_row[i] != '\r')
		i++;
	return (i);
}

void	read_map(char *map_name, t_game *game)
{
	int	fd;

	game->rows = count_lines(map_name);
	if (game->rows <= 0)
	{
		ft_printf("Error\nEmpty map! Check the map again...\n");
		ft_quit_game(game);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nProblem with the map file!");
		return ;
	}
	game->map = malloc(sizeof(char *) * (game->rows));
	if (!game->map)
		return ;
	fill_map (fd, game);
	game->columns = map_columns_len(game->map[0]);
	check_cloaker_number(game);
	init_cloaker(game, game->cloaker_number);
	close (fd);
}
