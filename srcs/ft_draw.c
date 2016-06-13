/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:35:14 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 18:59:31 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_dbl	*ft_lstforward(t_dbl *lst)
{
	t_dbl		*tmp;
	float		*ref;
	float		*trgt;

	if ((tmp = lst) != NULL)
	{
		ref = T_VECTOR->xyz;
		trgt = ref;
		while (tmp != NULL)
		{
			trgt = ((t_vector *)tmp->content)->xyz;
			if (trgt[0] == ref[0] && trgt[1] > ref[1])
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (tmp);
}

static void		ft_drawtwo(int *p1, int *p2, t_env *e)
{
	int			y;
	int			x;
	int			i;
	int			size;

	y = p1[1];
	i = -1;
	size = p2[1] - p1[1];
	while (y <= p2[1])
	{
		if (p2[1] != p1[1])
			x = p1[0] + ((p2[0] - p1[0]) * (y - p1[1])) / (p2[1] - p1[1]);
		else
			x = p1[0] + ((p2[0] - p1[0]) * (y - p1[1]));
		if (x >= 0 && x <= e->width && y >= 0 && y <= e->height)
			ft_pix_put_img(x, y, ft_color(p1[2], p2[2], ++i, size), e);
		++y;
	}
}

static void		ft_drawone(int *p1, int *p2, t_env *e)
{
	int			x;
	int			y;
	int			i;
	int			size;

	x = p1[0];
	size = p2[0] - p1[0];
	i = -1;
	while (x <= p2[0])
	{
		if (p2[0] != p1[0])
			y = p1[1] + ((p2[1] - p1[1]) * (x - p1[0])) / (p2[0] - p1[0]);
		else
			y = p1[1] + ((p2[1] - p1[1]) * (x - p1[0]));
		if (x >= 0 && x <= e->width && y >= 0 && y <= e->height)
			ft_pix_put_img(x, y, ft_color(p1[2], p2[2], ++i, size), e);
		++x;
	}
}

static void		ft_drawline(t_dbl *pt1, t_dbl *pt2, t_env *e)
{
	int			*xy1;
	int			*xy2;

	if (pt1 == NULL || pt2 == NULL)
		return ;
	xy1 = (int *)((t_vector *)pt1->content)->xycolor;
	xy2 = (int *)((t_vector *)pt2->content)->xycolor;
	if (ft_abs(xy2[0] - xy1[0]) > ft_abs(xy2[1] - xy1[1]))
	{
		if (xy1[0] <= xy2[0])
			ft_drawone(xy1, xy2, e);
		else
			ft_drawone(xy2, xy1, e);
	}
	else if (xy1[1] <= xy2[1])
		ft_drawtwo(xy1, xy2, e);
	else
		ft_drawtwo(xy2, xy1, e);
}

void			ft_draw(t_map *map, t_env *e)
{
	t_dbl		*tmp;
	t_vector	*pointa;
	t_vector	*pointb;

	if ((tmp = map->coord->head) != NULL)
	{
		while (tmp->next != NULL)
		{
			pointa = T_VECTOR;
			pointb = (t_vector *)tmp->next->content;
			if (pointa->xyz[0] < pointb->xyz[0])
				ft_drawline(tmp, tmp->next, e);
			ft_drawline(tmp, ft_lstforward(tmp), e);
			tmp = tmp->next;
		}
	}
}
