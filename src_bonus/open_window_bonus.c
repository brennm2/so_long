/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:32:05 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/02 19:58:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	display_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->columns * SIZE,
			game->rows * SIZE + 64, "so_long_bonus");
	if (game->win_ptr == NULL)
		return ;
}

void	render_hud_text(t_game *game)
{
	char	*moves;
	int		HUD_Y;
	int		HUD_X;

	HUD_Y = game->rows * SIZE;
	HUD_X = (game->columns / 2.7 ) * SIZE;
	moves = ft_itoa(game->moves);
	render_hud(game);
	if (game->coin_bag == game->collect)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, HUD_X + 20,
		HUD_Y + 35, 0xf70000, 
		"// POINT OF NO RETURN // MOVES :    //" );
		mlx_string_put(game->mlx_ptr, game->win_ptr, HUD_X + 219,
		HUD_Y + 35, 0xf70000, moves);
	}
	else
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, HUD_X ,
			HUD_Y + 35, 0xFFEF00, 
			"// POLICE ASSAULT IN PROGRESS // MOVES :    //" );
		mlx_string_put(game->mlx_ptr, game->win_ptr, HUD_X + 244,
			HUD_Y + 35, 0xFFEF00, moves);
	}
	free(moves);
}

void	render_hud(t_game	*game)
{
	int	i;

	i = 0;
	while (game->columns > i)
	{
		if (i == 0)
			put_texture(game, HUDBG_LEFT, game->rows * SIZE , i * SIZE);
		else if (i + 1 == game->columns)
			put_texture(game, HUDBG_RIGHT, game->rows * SIZE , i * SIZE);
		else if (i > 0 && i + 1 < game->columns)
			put_texture(game, HUDBG_MIDDLE, game->rows * SIZE , i * SIZE);
		i++;
	}
}
void	open_window(t_game *game)
{
	display_window(game);
	if (!game->win_ptr)
		return ;
	render_map (game);
	render_hud(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &key_handler, game);
	render_hud_text(game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		&ft_quit_game, game);
	mlx_loop(game->mlx_ptr);
}
