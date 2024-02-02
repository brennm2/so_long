/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:28:45 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/02 17:24:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	safe_house(t_game *game)
{
	if (game->map[game->player_position.y][game->player_position.x] == 'C')
	{
		game->map[game->player_position.y][game->player_position.x] = '0';
		game->coin_bag += 1;
	}
	if (game->map[game->player_position.y][game->player_position.x] == 'E')
	{
		if (game->coin_bag == game->collect)
		{
			put_texture(game, FLOOR, game->player_position.y * SIZE,
				game->player_position.x * SIZE);
			end_game_quotes(game);
			ft_quit_game(game);
		}
	}
	if (game->map[game->player_position.y][game->player_position.x] == 'X')
	{
		put_texture(game, PLAYER_DEAD, game->player_position.y * SIZE,
			game->player_position.x * SIZE);
		put_texture(game, PLAYER_DEAD, game->player_position.y * SIZE,
			game->player_position.x * SIZE);
		end_game_takedown(game);
	}
	game->moves += 1;
}

void	move_up(t_game *game)
{
	int	old_player;
	int	new_player;

	new_player = game->player_position.y - 1;
	old_player = game->player_position.y;
	if (game->map[new_player][game->player_position.x] == 'E')
	{
		put_texture(game, EXIT_PLAYER_UP_DOWN, new_player * SIZE,
			game->player_position.x * SIZE);
		put_texture(game, FLOOR, old_player * SIZE,
			game->player_position.x * SIZE);
		game->player_position.y = new_player;
		safe_house (game);
		return ;
	}
	put_texture(game, PLAYER_UP_DOWN, new_player * SIZE,
		game->player_position.x * SIZE);
	if (game->map[old_player][game->player_position.x] == 'E')
		put_texture(game, EXIT, old_player * SIZE,
			game->player_position.x * SIZE);
	else
		put_texture(game, FLOOR, old_player * SIZE,
			game->player_position.x * SIZE);
	game->player_position.y = new_player;
	safe_house (game);
}

void	move_down(t_game *game)
{
	int	old_player;
	int	new_player;

	new_player = game->player_position.y + 1;
	old_player = game->player_position.y;
	if (game->map[new_player][game->player_position.x] == 'E')
	{
		put_texture(game, EXIT_PLAYER_UP_DOWN, new_player * SIZE,
			game->player_position.x * SIZE);
		put_texture(game, FLOOR, old_player * SIZE,
			game->player_position.x * SIZE);
		game->player_position.y = new_player;
		safe_house (game);
		return ;
	}
	put_texture(game, PLAYER_UP_DOWN, new_player * SIZE,
		game->player_position.x * SIZE);
	if (game->map[old_player][game->player_position.x] == 'E')
		put_texture(game, EXIT, old_player * SIZE,
			game->player_position.x * SIZE);
	else
		put_texture(game, FLOOR, old_player * SIZE,
			game->player_position.x * SIZE);
	game->player_position.y = new_player;
	safe_house (game);
}

void	move_left(t_game *game)
{
	int	old_player;
	int	new_player;

	new_player = game->player_position.x - 1;
	old_player = game->player_position.x;
	if (game->map[game->player_position.y][new_player] == 'E')
	{
		put_texture(game, EXIT_PLAYER_LEFT, game->player_position.y * SIZE,
			new_player * SIZE);
		put_texture(game, FLOOR, game->player_position.y * SIZE,
			old_player * SIZE);
		game->player_position.x = new_player;
		safe_house (game);
		return ;
	}
	put_texture(game, PLAYER_LEFT, game->player_position.y * SIZE,
		new_player * SIZE);
	if (game->map[game->player_position.y][old_player] == 'E')
		put_texture(game, EXIT, game->player_position.y * SIZE,
			old_player * SIZE);
	else
		put_texture(game, FLOOR, game->player_position.y * SIZE,
			old_player * SIZE);
	game->player_position.x = new_player;
	safe_house (game);
}

void	move_right(t_game *game)
{
	int	old_player;
	int	new_player;

	new_player = game->player_position.x + 1;
	old_player = game->player_position.x;
	if (game->map[game->player_position.y][new_player] == 'E')
	{
		put_texture(game, EXIT_PLAYER, game->player_position.y * SIZE,
			new_player * SIZE);
		put_texture(game, FLOOR, game->player_position.y * SIZE,
			old_player * SIZE);
		game->player_position.x = new_player;
		safe_house (game);
		return ;
	}
	put_texture(game, PLAYER_RIGHT, game->player_position.y * SIZE,
		new_player * SIZE);
	if (game->map[game->player_position.y][old_player] == 'E')
		put_texture(game, EXIT, game->player_position.y * SIZE,
			old_player * SIZE);
	else
		put_texture(game, FLOOR, game->player_position.y * SIZE,
			old_player * SIZE);
	game->player_position.x = new_player;
	safe_house (game);
}
