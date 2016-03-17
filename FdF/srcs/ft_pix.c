/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 15:00:36 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/25 18:08:13 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_fdfgetcolor(int y1, int y2, int color1, int color2)
{
	if ((y2 - y1))
		return ((color2 - color1) / (y2 - y1));
	return (0);
}

static void	ft_draw_two(t_data p1, t_data p2, t_env *e)
{
	int		y;
	int		x;
	int		coloradd;
	int		i;

	y = p1.y;
	coloradd = ft_fdfgetcolor(p1.y, p2.y, p1.color, p2.color);
	i = 0;
	while (y <= p2.y)
	{
		if ((p2.y - p1.y) != 0)
			x = p1.x + ((p2.x - p1.x) * (y - p1.y)) / (p2.y - p1.y);
		else
			x = p1.x + ((p2.x - p1.x) * (y - p1.y));
		ft_pix_put_img(x, y, p1.color + (i * coloradd), e);
		y++;
	}
}

static void	ft_draw_one(t_data p1, t_data p2, t_env *e)
{
	int		x;
	int		y;

	x = p1.x;
	while (x <= p2.x)
	{
		if ((p2.x - p1.x) != 0)
			y = p1.y + ((p2.y - p1.y) * (x - p1.x)) / (p2.x - p1.x);
		else
			y = p1.y + ((p2.y - p1.y) * (x - p1.x));
		ft_pix_put_img(x, y, 0xFF0000, e);
		x++;
	}
}

static int	ft_abs(int n)
{
	if (n == -2147483648)
		return (2147483647);
	if (n < 0)
		n = -n;
	return (n);
}

void		ft_pix(t_data p1, t_data p2, t_env *e)
{
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y) && (p1.x <= p2.x))
		ft_draw_one(p1, p2, e);
	else if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y) && (p1.x >= p2.x))
		ft_draw_one(p2, p1, e);
	else if (p1.y <= p2.y)
		ft_draw_two(p1, p2, e);
	else
		ft_draw_two(p2, p1, e);
}
