/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/02 16:56:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	ft_quit_game(t_game *game)
{
	get_next_line(-1);
	free_all(game);
	exit (0);
}

void	free_map(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map);
		return ;
	}
	while (++i < game->rows)
		free(game->map[i]);
	free(game->map);
}

void	free_map_copy(char **map, t_game *game)
{
	int	i;

	i = -1;
	if (!map[0])
	{
		free (game->map_copy);
		return ;
	}
	while (++i < game->rows)
		free(game->map_copy[i]);
	free(game->map_copy);
}

void	free_cloaker(t_game *game)
{
	free(game->cloaker_position);
	game->cloaker_position = NULL;
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map, game);
	if (game->map_copy)
		free_map_copy(game->map_copy, game);
	if (game->cloaker_position)
		free_cloaker(game);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->img.mlx_img)
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free (game);
}
