/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:19:15 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 20:19:23 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		exit_callback(t_game *game)
{
	free(game);
	exit(0);
}

int		key_press_callback(int keycode, t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 1;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		key_release_callback(int keycode, t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 0;
	return (0);
}
