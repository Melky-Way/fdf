/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:40:29 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:44:14 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_fdfclean(e);
	else
		ft_getkey(keycode, e);
	return (0);
}

int				ft_expose_hook(t_env *e)
{
	ft_transformmap(e->map, e);
	ft_center(e->map, e);
	ft_draw(e->map, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void			ft_resetmatrixdata(t_env *e, t_matrix *matrix)
{
	if (matrix != NULL && e != NULL)
	{
		matrix->z = 0.6;
		matrix->y = -0.5;
		matrix->x = 2.80;
		matrix->trx = 0;
		matrix->try = 0;
		matrix->scale = 1;
		matrix->cntr[0] = e->width / 2;
		matrix->cntr[1] = e->height / 2;
	}
}

static int		ft_setenv(t_env *e, char *argv)
{
	int		endian;

	e->width = 1920;
	e->height = 1080;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "42");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->pix = mlx_get_data_addr(e->img, &e->bpp, &e->size_line, &endian);
	if ((e->mtrx = malloc(sizeof(t_matrix))) == NULL)
		return (-1);
	ft_resetmatrixdata(e, e->mtrx);
	ft_getmatrix(e->matrix);
	e->gradient = ft_getgradient(0);
	e->gradient2 = ft_getgradient(1);
	if ((e->map = ft_getmap(argv, e)) == NULL)
		return (-1);
	ft_transformmap(e->map, e);
	ft_scaletowindow(e->map, e);
	ft_center(e->map, e);
	return (1);
}

int				main(int argc, char **argv)
{
	t_env	e;

	if (argc == 1)
	{
		ft_putendl("usage : ./fdf file1");
		return (0);
	}
	if ((ft_setenv(&e, argv[1])) == -1)
	{
		ft_fdfclean(&e);
		return (1);
	}
	mlx_key_hook(e.win, ft_key_hook, &e);
	mlx_expose_hook(e.win, ft_expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
