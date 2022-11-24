/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeyrat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:52:59 by dpeyrat           #+#    #+#             */
/*   Updated: 2022/11/24 14:16:53 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <math.h>
# include <stdio.h>
# include "LIBFT/libft.h"
# include <mlx.h>

# define RED 0x00FF0000
# define FER 0x00FF1F00
# define REDOR 0x00FF3F00
# define VIV 0x00FF5F00
# define ORANGE 0x00FF7F00
# define PEEL 0x00FF9F00
# define AMBER 0x00FFBF00
# define GOLD 0x00FFDF00
# define YELLOW 0x00FFFF00
# define CHAR 0x00DFFF00
# define BITTER 0x00BFFF00
# define SPRING 0x009FFF00
# define LIME 0x007FFF00
# define BRIGR 0x005FFF00
# define HARL 0x003FFF00
# define ELEGR 0x001FFF00
# define GREEN 0x0000FF00
# define FREEGR 0x0000FF1F
# define MALACH 0x0000FF3F
# define GUPPIE 0x0000FF5F
# define TEAL 0x0000FF7F
# define MEDSPR 0x0000FF9F
# define SEAGR 0x0000FFBF
# define TURQU 0x0000FFDF
# define CYAN 0x0000FFFF
# define SKY 0x0000DFFF
# define CAPRI 0x0000BFFF
# define CERUL 0x00009FFF
# define AZURE 0x00007FFF
# define BRAND 0x00005FFF
# define DEBL 0x00003FFF
# define INTBLU 0x00001FFF
# define BLUE 0x000000FF
# define ULTRA 0x001F00FF
# define ELEUL 0x003F00FF
# define INDIGO 0x005F00FF
# define PURPLE 0x007F00FF
# define VIOLET 0x009F00FF
# define ELEPUR 0x00BF00FF
# define PHLOX 0x00DF00FF
# define MAGENTA 0x00FF00FF
# define FUSCHIA 0x00FF00DF
# define SHOCKPI 0x00FF00BF
# define FASHION 0x00FF009F
# define PINK 0x00FF007F
# define RASP 0x00FF005F
# define CRIMSON 0x00FF003F
# define RUDDY 0x00FF001F
# define BLACK 0x00000000

/*
# define RED 0x00FF0000
# define ORANGE 0x00FFFFFF
# define YELLOW 0x00FF0000
# define LIME 0x00FFFFFF
# define GREEN 0x00FF0000
# define TEAL 0x00FFFFFF
# define CYAN 0x00FF0000
# define AZURE 0x00FFFFFF
# define BLUE 0x00FF0000
# define PURPLE 0x00FFFFFF
# define MAGENTA 0x00FF0000
# define PINK 0x00FFFFFF
# define BLACK 0x00000000
*/

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linel;
	int		endian;
}				t_image;

typedef struct s_window
{
	int		x;
	int		y;

	double	r;
	double	i;

	int		f;
	double	zoom;

	void	*mlx;
	void	*wind;
	int		index;
	int		c;
	int		p;

	t_image	img;
	t_image img2;

	double	jr;
	double	ji;
}				t_window;

int			display_w(t_window *sc);
void		my_mlx_pixel_put(t_image *img, int x, int y, int colour);
double		ft_atof(char *str);
int			keypress(int keycode, t_window *sc);
int			mouseclick(int keycode, int x, int y, t_window *sc);
int			no_input(t_window *sc);
int			iterate_m(double r, double i, int c);
int			iterate_j(double r, double i, int c, t_window *sc);
int			iterate_b(double r, double i, int c);
void		set_image(t_window *sc, t_image img);
t_window	*param_error(t_window *sc);
int			check_mandel(char *str);
int			check_julia(char *str);
int			check_burning(char *str);
void		set_matrix(t_window *sc);
int			ft_exit(t_window *sc);

#endif
