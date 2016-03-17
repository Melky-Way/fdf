/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdfclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 21:42:20 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 17:37:06 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_freelst(t_dbl *lst)
{
	if (lst != NULL && lst->content != NULL)
	{
		free(lst->content);
		lst->content = NULL;
	}
}

void		ft_fdfclean(t_env *e)
{
	if (e != NULL)
	{
		if (e->map != NULL)
		{
			if (e->map->coord != NULL)
			{
				ft_dlist_iter(e->map->coord, ft_freelst);
				ft_dlist_del(&e->map->coord);
			}
			free(e->map);
			e->map = NULL;
		}
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		if (e->mtrx != NULL)
			free(e->mtrx);
		if (e->gradient != NULL)
			free(e->gradient);
		if (e->gradient2 != NULL)
			free(e->gradient2);
	}
	exit(0);
}
