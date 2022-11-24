/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:59:21 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:18:49 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_window	*parse2(int argc, char **argv, t_window *sc)
{
	sc->r = 0;
	sc->i = 0;
	sc->x = 640;
	sc->y = 480;
	sc->ji = 0;
	sc->jr = 0;
	sc->c = 0;
	sc->p = 0;
	if (sc->f == 1)
	{
		if (argc < 4)
			return (param_error(sc));
		sc->jr = ft_atof(argv[2]);
		sc->ji = ft_atof(argv[3]);
	}
	return (sc);
}

t_window	*parse(int argc, char **argv)
{
	t_window	*sc;

	if (argc < 2)
		return (param_error(0));
	sc = malloc(sizeof(t_window));
	if (!sc)
		return (0);
	if (!check_mandel(argv[1]))
		sc->f = 0;
	else if (!check_julia(argv[1]))
		sc->f = 1;
	else if (!check_burning(argv[1]))
		sc->f = 2;
	else
		return (param_error(sc));
	return (parse2(argc, argv, sc));
}

int	main(int argc, char **argv)
{
	t_window	*sc;

	sc = parse(argc, argv);
	if (!sc)
		return (-1);
	sc->zoom = 0.2;
	sc->mlx = mlx_init();
	sc->wind = mlx_new_window(sc->mlx, sc->x, sc->y, "Fract-ol");
	sc->img.img = mlx_new_image(sc->mlx, sc->x, sc->y);
	sc->img.addr = mlx_get_data_addr(sc->img.img, &sc->img.bpp,
			&sc->img.linel, &sc->img.endian);
	sc->img2.img = mlx_new_image(sc->mlx, sc->x, sc->y);
	sc->img2.addr = mlx_get_data_addr(sc->img2.img, &sc->img2.bpp,
			&sc->img2.linel, &sc->img2.endian);
	return (display_w(sc));
}
