/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:16 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/01 10:21:15 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	put_texture(t_game *game, char *texture_dir, int y, int x)
{
	if (game->img.mlx_img)
	{
		mlx_destroy_image(game->mlx_ptr, game->img.mlx_img);
		game->img.mlx_img = 0;
	}
	game->img.mlx_img = mlx_xpm_file_to_image (game->mlx_ptr, texture_dir,
			&game->img_size.x, &game->img_size.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img.mlx_img, x, y);
}

void	render_textures(t_game *game, int y, int x)
{
	char	position;

	position = game->map[y][x];
	if (position == '1')
		put_texture(game, "./textures/WALL.xpm", y * SIZE, x * SIZE);
	else if (position == '0')
		put_texture(game, "./textures/FLOOR.xpm", y * SIZE, x * SIZE);
	else if (position == 'C')
		put_texture(game, "./textures/COIN.xpm", y * SIZE, x * SIZE);
	else if (position == 'E')
		put_texture(game, "./textures/EXIT.xpm", y * SIZE, x * SIZE);
	else if (position == 'P')
		put_texture(game, "./textures/PLAYER.xpm", y * SIZE, x * SIZE);
	else if (position == 'X')
		put_texture(game, CLOAKER, y * SIZE, x * SIZE);
}

void	render_map(t_game *game)
{
	game->coordinates.y = 0;
	while (game->coordinates.y < game->rows)
	{
		game->coordinates.x = 0;
		while (game->coordinates.x < game->columns)
		{
			render_textures(game, game->coordinates.y, game->coordinates.x);
			game->coordinates.x += 1;
		}
		game->coordinates.y += 1;
	}
}
