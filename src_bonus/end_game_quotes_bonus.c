/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_quotes_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:39:51 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/03 11:06:35 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	end_0(void)
{
	ft_printf("\n\n- Bain: I bet they don't know what hit them!\n");
	usleep(3000000);
	ft_printf("	But I know the action is the juice for some of you.\n");
	usleep(3000000);
	ft_printf("	So, I got more heists for you to stick your teeth in to.\n");
	usleep(3000000);
	ft_printf("	I'm sure we'll be working together again shortly.\n\n");
	usleep(3000000);
}

void	end_1(void)
{
	ft_printf("\n\n- Bain: That's how you do it, people!\n");
	usleep(3000000);
	ft_printf("	I got more heists lined up for you.\n");
	usleep(3000000);
	ft_printf("	I hope you're ready to work again soon.\n");
	usleep(3000000);
	ft_printf("	So... wanna do some another hit?\n\n");
	usleep(3000000);
}

void	end_2(void)
{
	ft_printf("\n\n- Bain: They weren't expecting that, for god-damn sure!\n");
	usleep(3000000);
	ft_printf("	Still, we got more scores to take down.\n");
	usleep(3000000);
	ft_printf("	And the plans have your name written all over them.\n");
	usleep(3000000);
	ft_printf("	Hope to work again in the near future.\n\n");
	usleep(3000000);
}

void	end_3(void)
{
	ft_printf("\n\n- Bain: We are set for life!\n");
	usleep(3000000);
	ft_printf("	But… maybe you want to do some another hit");
	ft_printf(" just for the action, huh?\n");
	usleep(3000000);
	ft_printf("	See you at the safe house,");
	ft_printf(" I'll show you the plans...\n\n");
	usleep(3000000);
}

void	end_game_quotes(t_game *game)
{
	int		end_number;
	time_t	t;

	srand((unsigned) time(&t));
	end_number = rand() % 4;
	if (end_number == 0 || end_number == 1)
	{
		if (game->cloaker_number > 7)
			end_game_death_wish_quotes();
		else if (end_number == 0)
			end_0 ();
		else
			end_1 ();
	}
	else if (end_number == 2 || end_number == 3)
	{
		if (game->cloaker_number > 7)
			end_game_death_wish_quotes();
		else if (end_number == 2)
			end_2 ();
		else
			end_3 ();
	}
}
