/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:27:04 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:23:40 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	ft_exit(t_window *sc)
{
	free(sc);
	exit(0);
	return (0);
}

void	render(t_window *sc)
{
	if (sc->p)
	{
		if (sc->c == 47)
			sc->c = 0;
		else
			sc->c++;
	}
	if (sc->index)
	{
		set_image(sc, sc->img);
		mlx_put_image_to_window(sc->mlx, sc->wind, sc->img.img, 0, 0);
	}
	else
	{
		set_image(sc, sc->img2);
		mlx_put_image_to_window(sc->mlx, sc->wind, sc->img2.img, 0, 0);
	}
	sc->index = !sc->index;
}

int	no_input(t_window *sc)
{
	render(sc);
	return (0);
}

int	keypress(int keycode, t_window *sc)
{
	if (keycode == 13)
		sc->i = sc->i - (25 * (0.002 / sc->zoom));
	else if (keycode == 1)
		sc->i = sc->i + (25 * (0.002 / sc->zoom));
	else if (keycode == 0)
		sc->r = sc->r - (25 * (0.002 / sc->zoom));
	else if (keycode == 2)
		sc->r = sc->r + (25 * (0.002 / sc->zoom));
	else if (keycode == 53)
		ft_exit(sc);
	else if (keycode == 126)
		sc->zoom = sc->zoom * 1.1;
	else if (keycode == 125)
		sc->zoom = sc->zoom / 1.1;
	else if (keycode == 48)
	{
		sc->r = 0;
		sc->i = 0;
		sc->zoom = 0.2;
	}
	else if (keycode == 35)
		sc->p = !sc->p;
	return (0);
}

int	mouseclick(int keycode, int x, int y, t_window *sc)
{
	if (keycode == 1)
	{
		sc->r = sc->r + (((double)x - (sc->x / 2)) * (0.002 / sc->zoom));
		sc->i = sc->i + (((double)y - (sc->y / 2)) * (0.002 / sc->zoom));
	}
	else if (keycode == 5)
	{

		sc->zoom = sc->zoom * 1.1;
		sc->r = sc->r + ((double)(x - (sc->x / 2)) * (0.002 / sc->zoom) * ((1.0 - (1.0 / 1.1))));
		sc->i = sc->i - ((double)(y - (sc->y / 2)) * (0.002 / sc->zoom) * ((1.0 - (1.0 / 1.1))));
	}
	else if (keycode == 4)
	{
		sc->zoom = sc->zoom / 1.1;
		sc->r = sc->r - ((double)(x - (sc->x / 2)) * (0.002 / sc->zoom) * ((0.1)));
		sc->i = sc->i + ((double)(y - (sc->y / 2)) * (0.002 / sc->zoom) * ((0.1)));
	}
	return (0);
}
