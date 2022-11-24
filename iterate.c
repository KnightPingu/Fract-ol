/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:29:17 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:12:24 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	iterate_m(double r, double i, int c)
{
	int		j;
	double	it_r;
	double	it_i;
	double	temp_r;
	double	temp_i;

	it_r = 0;
	it_i = 0;
	j = 0;
	while ((it_r * it_r) + (it_i * it_i) < 4 && j < c)
	{
		j++;
		temp_r = (it_r * it_r) - (it_i * it_i) + r;
		temp_i = ((it_r * it_i) * 2) + i;
		if (temp_r == it_r && temp_i == it_i)
			return (-1);
		it_r = temp_r;
		it_i = temp_i;
	}
	if (j == c)
		return (-1);
	return (j);
}

int	iterate_j(double r, double i, int c, t_window *sc)
{
	int		j;
	double	it_r;
	double	it_i;
	double	temp_r;
	double	temp_i;

	it_r = r;
	it_i = i;
	j = 0;
	while ((it_r * it_r) + (it_i * it_i) < 4 && j < c)
	{
		j++;
		temp_r = (it_r * it_r) - (it_i * it_i) + sc->jr;
		temp_i = (2 * (it_r * it_i)) + sc->ji;
		if (temp_r == it_r && temp_i == it_i)
			return (-1);
		it_r = temp_r;
		it_i = temp_i;
	}
	if (j == c)
		return (-1);
	return (j);
}

int	iterate_b(double r, double i, int c)
{
	int		j;
	double	it_r;
	double	it_i;
	double	temp_r;
	double	temp_i;

	it_r = r;
	it_i = i;
	j = 0;
	while ((it_r * it_r) + (it_i * it_i) < 4 && j < c)
	{
		it_r = fabs(it_r);
		it_i = fabs(it_i);
		temp_r = it_r * it_r - it_i * it_i + r;
		temp_i = 2 * it_r * it_i + i;
		if (temp_r == it_r && temp_i == it_i)
			return (-1);
		it_r = temp_r;
		it_i = temp_i;
		j++;
	}
	if (j == c)
		return (-1);
	return (j);
}
