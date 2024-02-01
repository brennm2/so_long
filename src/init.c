/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:17 by bde-souz          #+#    #+#             */
/*   Updated: 2024/01/31 11:26:07 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->map_name = NULL;
	game->moves = 0;
	game->columns = 0;
	game->rows = 0;
	game->collect = 0;
	game->collect_check = 0;
	game->coin_bag = 0;
	game->exit_check = 0;
	game->coordinates.x = 0;
	game->coordinates.y = 0;
	game->img_size.y = 0;
	game->img_size.x = 0;
}

void	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = NULL;
	game->img.mlx_img = NULL;
	game->img.addr = NULL;
	game->img.bpp = 0;
	game->img.line_len = 0;
	game->img.endian = 0;
	game->img_size.y = SIZE;
	game->img_size.x = SIZE;
}

t_game	*init(void)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		return (NULL);
	init_game(game);
	init_window(game);
	return (game);
}
