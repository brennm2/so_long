/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cloaker_move_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:09:26 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/02 17:08:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	move_cloaker_up(t_game *game, int i)
{
	int	old_cloaker;
	int	new_cloaker;

	new_cloaker = game->cloaker_position[i].y - 1;
	old_cloaker = game->cloaker_position[i].y;
	check_cloaker_takedown(game, i);
	if (game->map[new_cloaker][game->cloaker_position[i].x] == '0'
		|| game->map[new_cloaker][game->cloaker_position[i].x] == 'P')
	{
		put_texture(game, FLOOR, old_cloaker * SIZE,
			game->cloaker_position[i].x * SIZE);
		put_texture(game, CLOAKER, new_cloaker * SIZE,
			game->cloaker_position[i].x * SIZE);
		game->cloaker_position[i].y = new_cloaker;
		check_cloaker_takedown(game, i);
		game->map[old_cloaker][game->cloaker_position[i].x] = '0';
		game->map[new_cloaker][game->cloaker_position[i].x] = 'X';
		return (0);
	}
	return (-1);

}

int	move_cloaker_down(t_game *game, int i)
{
	int	old_cloaker;
	int	new_cloaker;

	new_cloaker = game->cloaker_position[i].y + 1;
	old_cloaker = game->cloaker_position[i].y;
	check_cloaker_takedown(game, i);
	if (game->map[new_cloaker][game->cloaker_position[i].x] == '0'
		|| game->map[new_cloaker][game->cloaker_position[i].x] == 'P')
	{
		put_texture(game, FLOOR, old_cloaker * SIZE,
			game->cloaker_position[i].x * SIZE);
		put_texture(game, CLOAKER, new_cloaker * SIZE,
			game->cloaker_position[i].x * SIZE);
		game->cloaker_position[i].y = new_cloaker;
		check_cloaker_takedown(game, i);
		game->map[old_cloaker][game->cloaker_position[i].x] = '0';
		game->map[new_cloaker][game->cloaker_position[i].x] = 'X';
		return (0);
	}
	return (-1);
}

int	move_cloaker_left(t_game *game, int i)
{
	int	old_cloaker;
	int	new_cloaker;

	new_cloaker = game->cloaker_position[i].x - 1;
	old_cloaker = game->cloaker_position[i].x;
	check_cloaker_takedown(game, i);
	if (game->map[game->cloaker_position[i].y][new_cloaker] == '0'
		|| game->map[game->cloaker_position[i].y][new_cloaker] == 'P')
	{
		put_texture(game, FLOOR, game->cloaker_position[i].y * SIZE,
			old_cloaker * SIZE);
		put_texture(game, CLOAKER, game->cloaker_position[i].y * SIZE,
			new_cloaker * SIZE);
		game->cloaker_position[i].x = new_cloaker;
		check_cloaker_takedown(game, i);
		game->map[game->cloaker_position[i].y][old_cloaker] = '0';
		game->map[game->cloaker_position[i].y][new_cloaker] = 'X';
		return (0);
	}
	return (-1);
}

int	move_cloaker_right(t_game *game, int i)
{
	int	old_cloaker;
	int	new_cloaker;

	new_cloaker = game->cloaker_position[i].x + 1;
	old_cloaker = game->cloaker_position[i].x;
	check_cloaker_takedown(game, i);
	if (game->map[game->cloaker_position[i].y][new_cloaker] == '0'
		|| game->map[game->cloaker_position[i].y][new_cloaker] == 'P')
	{
		put_texture(game, FLOOR, game->cloaker_position[i].y * SIZE,
			old_cloaker * SIZE);
		put_texture(game, CLOAKER, game->cloaker_position[i].y * SIZE,
			new_cloaker * SIZE);
		game->cloaker_position[i].x = new_cloaker;
		check_cloaker_takedown(game, i);
		game->map[game->cloaker_position[i].y][old_cloaker] = '0';
		game->map[game->cloaker_position[i].y][new_cloaker] = 'X';
		return (0);
	}
	return (-1);
}

void	move_cloaker(t_game *game)
{
	int	i;
	int	direction;
	int	v;

	i = 0;
	v = 0;
	while (game->cloaker_number > i)
	{
		direction = rand() % 4;
		if (direction == 0 && move_cloaker_up(game, i) != -1)
			v++;
		else if (direction == 1 && move_cloaker_down(game, i) != -1)
			v++;
		else if (direction == 2 && move_cloaker_left(game, i) != -1)
			v++;
		else if (direction == 3 && move_cloaker_right(game, i) != -1)
			v++;
		i++;
	}
}
