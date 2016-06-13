/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pix_put_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:49:05 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 18:55:41 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pix_put_img(int x, int y, int color, t_env *e)
{
	int		i;

	if (y < e->height && x < e->width && x >= 0 && y >= 0)
	{
		i = (x * 4) + (y * e->width * 4);
		e->pix[i++] = (char)color;
		e->pix[i++] = (char)(color >> 8);
		e->pix[i] = (char)(color >> 16);
	}
}
