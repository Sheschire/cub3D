/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_sound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:46:47 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 13:47:04 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	play_sound_2(char c)
{
	if (PLATFORM == 1)
	{
		if (c == 's')
			system("afplay ./sounds/snorlax.mp3 &");
		if (c == 'c')
			system("afplay ./sounds/capture.mp3 &");
		if (c == 'o')
			system("afplay ./sounds/pick_obj.mp3 &");
		if (c == 'v')
			system("afplay ./sounds/victory.mp3 &");
		if (c == 'x')
			system("killall afplay");
	}
}

void	play_sound(char c)
{
	if (PLATFORM == 1)
	{
		if (c == 'r')
			system("afplay ./sounds/route1.mp3 &");
		if (c == 'l')
			system("afplay ./sounds/lugia.mp3 &");
		if (c == 't')
			system("afplay ./sounds/lugia_theme.mp3 &");
		if (c == 'z')
			system("afplay ./sounds/rayquaza.mp3 &");
		if (c == 'q')
			system("afplay ./sounds/rayquaza_theme.mp3 &");
		if (c == 'y')
			system("afplay ./sounds/typhlosion.mp3 &");
	}
	play_sound_2(c);
}