/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:26:39 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:16:10 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	get_ind_colour(int c)
{
	if (c == 47)
		return (RUDDY);
	if (c == 46)
		return (CRIMSON);
	if (c == 45)
		return (RASP);
	if (c == 44)
		return (PINK);
	if (c == 43)
		return (FASHION);
	if (c == 42)
		return (SHOCKPI);
	if (c == 41)
		return (FUSCHIA);
	if (c == 40)
		return (MAGENTA);
	if (c == 39)
		return (PHLOX);
	if (c == 38)
		return (ELEPUR);
	if (c == 37)
		return (VIOLET);
	if (c == 36)
		return (PURPLE);
	if (c == 35)
		return (INDIGO);
	if (c == 34)
		return (ELEUL);
	if (c == 33)
		return (ULTRA);
	if (c == 32)
		return (BLUE);
	if (c == 31)
		return (INTBLU);
	if (c == 30)
		return (DEBL);
	if (c == 29)
		return (BRAND);
	if (c == 28)
		return (AZURE);
	if (c == 27)
		return (CERUL);
	if (c == 26)
		return (CAPRI);
	if (c == 25)
		return (SKY);
	if (c == 24)
		return (CYAN);
	if (c == 23)
		return (TURQU);
	if (c == 22)
		return (SEAGR);
	if (c == 21)
		return (MEDSPR);
	if (c == 20)
		return (TEAL);
	if (c == 19)
		return (GUPPIE);
	if (c == 18)
		return (MALACH);
	if (c == 17)
		return (FREEGR);
	if (c == 16)
		return (GREEN);
	if (c == 15)
		return (ELEGR);
	if (c == 14)
		return (HARL);
	if (c == 13)
		return (BRIGR);
	if (c == 12)
		return (LIME);
	if (c == 11)
		return (SPRING);
	if (c == 10)
		return (BITTER);
	if (c == 9)
		return (CHAR);
	if (c == 8)
		return (YELLOW);
	if (c == 7)
		return (GOLD);
	if (c == 6)
		return (AMBER);
	if (c == 5)
		return (PEEL);
	if (c == 4)
		return (ORANGE);
	if (c == 3)
		return (VIV);
	if (c == 2)
		return (REDOR);
	if (c == 1)
		return (FER);
	return (RED);
}

int	get_pixel_colour(t_window *sc, int y, int x)
{
	int		c;
	double	real;
	double	imaginary;

	real = sc->r + (((double)x - (sc->x / 2)) * (0.002 / sc->zoom));
	imaginary = sc->i + (((double)y - (sc->y / 2)) * (0.002 / sc->zoom));
	if (sc->f == 0)
		c = iterate_m(real, imaginary, fmax(5 * sc->zoom, 100));
	else if (sc->f == 1)
		c = iterate_j(real, imaginary, fmax(5 * sc->zoom, 100), sc);
	else
		c = iterate_b(real, imaginary, fmax(5 * sc->zoom, 100));
	if (c == -1)
		return (BLACK);
	return (get_ind_colour((c + sc->c) % 48));
}

void	set_image(t_window *sc, t_image img)
{
	int	i;
	int	j;

	i = 0;
	while (i < sc->y)
	{
		j = 0;
		while (j < sc->x)
		{
			my_mlx_pixel_put(&img, j, i, get_pixel_colour(sc, i, j));
			j++;
		}
		i++;
	}
}

int	display_w(t_window *sc)
{
	sc->index = 0;
	set_image(sc, sc->img);
	mlx_put_image_to_window(sc->mlx, sc->wind, sc->img.img, 0, 0);
	mlx_key_hook(sc->wind, keypress, sc);
	mlx_mouse_hook(sc->wind, mouseclick, sc);
	mlx_loop_hook(sc->mlx, no_input, sc);
	mlx_hook(sc->wind, 17, 0, ft_exit, sc);
	mlx_loop(sc->mlx);
	return (0);
}
