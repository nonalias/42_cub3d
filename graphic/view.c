/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 22:49:18 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/19 16:58:03 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_view(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx_ptr,
			game->win.width, game->win.height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
			&game->img.bpp, &game->img.size_l, &game->img.endian);
	make_3d(game);
	make_2d(game);
	make_rader(game);
	make_crosshair(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.img_ptr, 0, 0);
	if (game->flags.debug)
		status_show(game);
	if (game->flags.save)
	{
		if (!save_bmp(game))
			error_exit(game, MAP_ERROR, "couldn't save screenshot");
		mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
		free(game);
		exit(0);
	}
	mlx_destroy_image(game->mlx_ptr, game->img.img_ptr);
}
