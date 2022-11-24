/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:20:29 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:13:22 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_window	*param_error(t_window *sc)
{
	free(sc);
	printf("Correct Arguements:\n");
	printf("Mandelbrot, Julia, Burning\n");
	printf("If Julia is selected, provide a complex number\n");
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image *img, int x, int y, int colour)
{
	char	*dst;

	dst = img->addr + (y * img->linel + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

double	ft_atof2(char *str, double res, double n, int i)
{
	double	t;

	t = 10;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res + ((double) str[i] - 48) / t;
		t = t * 10;
		i++;
	}
	return (res * n);
}

double	ft_atof(char *str)
{
	int		i;
	double	n;
	double	res;

	res = 0;
	i = 0;
	n = 1;
	if (str[0] == '-')
	{
		i = 1;
		n = -1;
	}
	while (str[i] != '.' && str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	return (ft_atof2(str, res, n, i));
}
