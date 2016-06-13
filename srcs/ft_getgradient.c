/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 20:52:01 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:21:16 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_colorpoints(t_map *map, int *gradient)
{
	t_dbl	*tmp;
	int		i;
	double	margin;

	if (!map || !(map->coord) || (tmp = map->coord->head) == NULL)
		return ;
	margin = (map->absolute[0] - map->absolute[1]) / 100.00;
	while (tmp != NULL)
	{
		i = !margin ? 0 : (T_VECTOR->xyz[2] - map->absolute[1]) / margin;
		i = i > 99 ? 99 : i;
		T_VECTOR->xycolor[2] = gradient[i];
		tmp = tmp->next;
	}
}

int			ft_color(int cola, int colb, int i, int size)
{
	int		rgb1[3];
	int		rgb2[3];
	int		rgb3[3];
	int		gradient;

	if (cola == colb)
		return (cola);
	rgb1[0] = (cola >> 16) & 0xFF;
	rgb1[1] = (cola >> 8) & 0xFF;
	rgb1[2] = cola & 0xFF;
	rgb2[0] = (colb >> 16) & 0xFF;
	rgb2[1] = (colb >> 8) & 0xFF;
	rgb2[2] = colb & 0xFF;
	rgb3[0] = rgb1[0] + ((rgb2[0] - rgb1[0]) * (float)i / (float)size);
	rgb3[1] = rgb1[1] + ((rgb2[1] - rgb1[1]) * (float)i / (float)size);
	rgb3[2] = rgb1[2] + ((rgb2[2] - rgb1[2]) * (float)i / (float)size);
	gradient = (00 << 24) + ((rgb3[0] & 0xff) << 16) + \
	((rgb3[1] & 0xff) << 8) + (rgb3[2] & 0xff);
	return (gradient);
}

static int	ft_rgbref(int i)
{
	int		colorarray[6];

	colorarray[0] = 0x000099;
	colorarray[1] = 0x33ccff;
	colorarray[2] = 0xffff66;
	colorarray[3] = 0x33cc33;
	colorarray[4] = 0x663300;
	colorarray[5] = 0xffffff;
	if (i <= 5)
		return (colorarray[i]);
	return (0);
}

int			ft_getcolor(int *gradient, int *absolute, int z)
{
	int		i;
	float	margin;

	margin = (absolute[0] - absolute[1]) / 100.00;
	i = (z / margin) > absolute[0] ? absolute[0] : (z / margin);
	return (gradient[i]);
}

int			*ft_getgradient(int mode)
{
	int		*gradient;
	int		i;
	int		j;

	gradient = ft_memalloc(sizeof(int) * 100);
	i = -1;
	j = 0;
	while (++i < 100)
	{
		j += !(i % 20) && i ? 1 : 0;
		if (mode)
			gradient[i] = ft_color(0x333333, 0xffffff, i, 99);
		else
			gradient[i] = ft_color(ft_rgbref(j), ft_rgbref(j + 1), i % 20, 20);
	}
	return (gradient);
}
