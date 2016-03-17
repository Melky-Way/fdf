/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applymatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 12:37:13 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:19:14 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define X xyz[0]
#define Y xyz[1]
#define Z xyz[2]
#define MATRIX e->matrix

static void	ft_translation(int key, t_matrix *mtrx)
{
	if (key == 123 || key == 124)
		mtrx->cntr[0] += key == 123 ? -40 : 40;
	else
		mtrx->cntr[1] += key == 125 ? 40 : -40;
}

static void	ft_flattenextrude(int key, t_env *e)
{
	float	scale;
	t_dbl	*tmp;

	scale = key == 75 ? 0.9 : 1.1;
	tmp = e->map->coord->head;
	e->map->absolute[0] *= scale;
	e->map->absolute[1] *= scale;
	while (tmp != NULL)
	{
		T_VECTOR->xyz[2] *= scale;
		tmp = tmp->next;
	}
}

static void	ft_modifyrotation(t_env *e, int key)
{
	float		angle;

	angle = (key == 86 || key == 91 || key == 82) ? -0.1 : 0.1;
	if (key == 86 || key == 88)
		e->mtrx->z += angle;
	else if (key == 84 || key == 91)
		e->mtrx->y += angle;
	else if (key == 82 || key == 65)
		e->mtrx->x += angle;
}

void		ft_getkey(int key, t_env *e)
{
	if (key == 86 || key == 88 || key == 84 || \
		key == 91 || key == 82 || key == 65)
		ft_modifyrotation(e, key);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_translation(key, e->mtrx);
	else if (key == 69 || key == 78)
		e->mtrx->scale *= key == 69 ? 1.1 : 0.9;
	else if (key == 75 || key == 67)
		ft_flattenextrude(key, e);
	else if (key == 71)
		ft_colorpoints(e->map, e->gradient);
	else if (key == 81)
		ft_colorpoints(e->map, e->gradient2);
	else if (key == 87)
		ft_resetmatrixdata(e, e->mtrx);
	mlx_clear_window(e->mlx, e->win);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	ft_expose_hook(e);
}

void		ft_applymatrix(float *xyz, int *xycolor, float *matrix)
{
	xycolor[0] = X * matrix[0] + Y * matrix[1] + Z * matrix[2] + matrix[3];
	xycolor[1] = X * matrix[4] + Y * matrix[5] + Z * matrix[6] + matrix[7];
}
