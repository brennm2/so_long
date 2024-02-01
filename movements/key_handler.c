/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:49:27 by bde-souz          #+#    #+#             */
/*   Updated: 2024/01/31 12:14:33 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		ft_printf("\n'ESC' pressed, game closed...\nThanks for playing!\n");
		ft_quit_game(game);
	}
	if (key == 'w' || key == XK_Up)
		test_move_up(game);
	if (key == 's' || key == XK_Down)
		test_move_down(game);
	if (key == 'a' || key == XK_Left)
		test_move_left(game);
	if (key == 'd' || key == XK_Right)
		test_move_right(game);
	return (0);
}

void	test_move_up(t_game *game)
{
	if (game->map[game->player_position.y - 1]
		[game->player_position.x] == '1')
		return ;
	move_up (game);
}

void	test_move_down(t_game *game)
{
	if (game->map[game->player_position.y + 1]
		[game->player_position.x] == '1')
		return ;
	move_down (game);
}

void	test_move_left(t_game *game)
{
	if (game->map[game->player_position.y]
		[game->player_position.x - 1] == '1')
		return ;
	move_left(game);
}

void	test_move_right(t_game *game)
{
	if (game->map[game->player_position.y]
		[game->player_position.x + 1] == '1')
		return ;
	move_right(game);
}
