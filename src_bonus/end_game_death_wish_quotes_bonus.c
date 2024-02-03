/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_death_wish_quotes_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:14:33 by bde-souz          #+#    #+#             */
/*   Updated: 2024/02/03 10:47:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	end_dw0(void)
{
	ft_printf("\n\n- Bain: How are you guys holding up?\n");
	usleep(3000000);
	ft_printf("	You just barely survived that one.\n");
	usleep(3000000);
	ft_printf("	Get yourselves patched up and get back in the game.\n\n");
	usleep(3000000);
}

void	end_dw1(void)
{
	ft_printf("\n\n- Bain: I'm glad to see you guys survived that...\n");
	usleep(3000000);
	ft_printf("	Even though it was just barely.\n");
	usleep(3000000);
	ft_printf("	It won't be long until the next assault wave, though.\n");
	ft_printf("	But focus on the plan.\n\n");
	usleep(3000000);
}

void	end_dw2(void)
{
	ft_printf("\n\n- Bain: *sigh*... That was closer than I'd like people...\n");
	usleep(3000000);
	ft_printf("	You did good back there, take advantage of it now.\n");
	usleep(3000000);
	ft_printf("	They'll be back for more, so don't mess around.\n\n");
	usleep(3000000);
}

void	end_dw3(void)
{
	ft_printf("\n\n- Bain: God-damn it! You had me worried back there...\n");
	usleep(3000000);
	ft_printf("	That could have gone better...\n");
	ft_printf("	But it definitely could have gone worse.\n");
	usleep(3000000);
	ft_printf("	Now, get to work you don't have all day\n\n");
	usleep(3000000);
}

void	end_game_death_wish_quotes(void)
{
	int		end_dwnumber;
	time_t	t;

	srand((unsigned) time(&t));
	end_dwnumber = rand() % 4;
	if (end_dwnumber == 0)
		end_dw0();
	else if (end_dwnumber == 1)
		end_dw1();
	else if (end_dwnumber == 2)
		end_dw2();
	else if (end_dwnumber == 3)
		end_dw3();
}
