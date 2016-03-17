/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixoperations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:37:07 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:37:09 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>

void			ft_getmatrix(float *matrix)
{
	ft_bzero(matrix, sizeof(matrix));
	matrix[0] = 1;
	matrix[5] = 1;
	matrix[10] = 1;
	matrix[15] = 1;
}

void			ft_makerotation(float *matrix, float z, float y, float x)
{
	float	math[6];

	math[0] = cosf(x);
	math[1] = cosf(y);
	math[2] = cosf(z);
	math[3] = sinf(x);
	math[4] = sinf(y);
	math[5] = sinf(z);
	matrix[0] = math[2] * math[1];
	matrix[1] = -math[5];
	matrix[2] = math[2] * math[4];
	matrix[4] = math[2] * (math[5] * math[1]) + -math[3] * -math[4];
	matrix[5] = math[2] * math[2];
	matrix[6] = math[2] * (math[5] * math[4]) + -math[3] * math[1];
	matrix[8] = math[3] * (math[5] * math[1]) + math[0] * -math[4];
	matrix[9] = math[3] * math[2];
	matrix[10] = math[3] * (math[5] * math[4]) + math[0] * math[1];
}

void			ft_maketranslation(float *matrix, int x, int y)
{
	matrix[3] += x;
	matrix[7] += y;
}

void			ft_scaling(float *matrix, float factor)
{
	int		i;

	i = -1;
	while (++i < 11)
		matrix[i] *= (i == 3 || i == 7) ? 1 : factor;
}

void			ft_changematrix(t_env *e)
{
	if (e != NULL && e->mtrx != NULL)
	{
		ft_getmatrix(e->matrix);
		ft_makerotation(e->matrix, e->mtrx->z, e->mtrx->y, e->mtrx->x);
		ft_maketranslation(e->matrix, e->mtrx->trx, e->mtrx->try);
		ft_scaling(e->matrix, e->mtrx->scale);
	}
}
