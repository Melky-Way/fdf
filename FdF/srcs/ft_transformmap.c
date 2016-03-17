/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformmap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:14:54 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 18:58:56 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define X T_VECTOR->xycolor[0]
#define Y T_VECTOR->xycolor[1]

static void	ft_initsize(int *size, int *xycolor)
{
	if (size != NULL && xycolor != NULL)
	{
		size[0] = xycolor[0];
		size[1] = xycolor[0];
		size[2] = xycolor[1];
		size[3] = xycolor[1];
	}
}

void		ft_transformmap(t_map *obj, t_env *e)
{
	t_dbl	*tmp;
	int		i;

	i = 0;
	tmp = obj->coord->head;
	ft_changematrix(e);
	while (tmp != NULL)
	{
		ft_applymatrix(T_VECTOR->xyz, T_VECTOR->xycolor, e->matrix);
		if (!i++)
			ft_initsize(obj->size, T_VECTOR->xycolor);
		obj->size[0] = obj->size[0] < X ? X : obj->size[0];
		obj->size[1] = obj->size[1] > X ? X : obj->size[1];
		obj->size[2] = obj->size[2] < Y ? Y : obj->size[2];
		obj->size[3] = obj->size[3] > Y ? Y : obj->size[3];
		tmp = tmp->next;
	}
	obj->cntr[0] = (obj->size[0] - obj->size[1]) / 2 + obj->size[1];
	obj->cntr[1] = (obj->size[2] - obj->size[3]) / 2 + obj->size[3];
	obj->cntr[2] = 0;
}
