/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scaleandcenter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 15:47:59 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 18:56:29 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_center(t_map *obj, t_env *e)
{
	e->mtrx->trx = e->mtrx->cntr[0] - obj->cntr[0];
	e->mtrx->try = e->mtrx->cntr[1] - obj->cntr[1];
	ft_transformmap(obj, e);
}

void		ft_scaletowindow(t_map *obj, t_env *e)
{
	float	scale;
	int		span[2];

	span[0] = obj->size[0] - obj->size[1];
	span[1] = obj->size[2] - obj->size[3];
	scale = 0.90;
	while (span[0] * scale > e->width * 0.80 && \
			span[1] * scale > e->height * 0.80)
		scale -= 0.05;
	while (span[0] * scale < e->width * 0.80 && \
			span[1] * scale < e->height * 0.80)
		scale += 0.05;
	e->mtrx->scale = scale;
	ft_transformmap(obj, e);
}
