/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:20:33 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:43:50 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define FDOK "fd >= 0 && fd <= 2"
# define TRANSLATE 0
# define SCALE 1
# define ROTATE 2
# define T_VECTOR ((t_vector *)tmp->content)

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_vector
{
	float		xyz[3];
	int			xycolor[3];
}				t_vector;

typedef struct	s_map
{
	t_dlist		*coord;
	int			xy[2];
	int			cntr[3];
	int			size[4];
	int			absolute[2];
}				t_map;

typedef struct	s_matrix
{
	float		z;
	float		y;
	float		x;
	int			trx;
	int			try;
	float		scale;
	int			cntr[2];
}				t_matrix;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	char		*pix;
	t_map		*map;
	t_matrix	*mtrx;
	float		matrix[16];
	int			*gradient;
	int			*gradient2;
	int			cntr[2];
}				t_env;

/*
** ft_pix_put_img.c
*/
void			ft_pix_put_img(int x, int y, int color, t_env *e);

/*
** ft_matrixoperations.c
*/
void			ft_getmatrix(float *matrix);
void			ft_makerotation(float *matrix, float z, float y, float x);
void			ft_maketranslation(float *matrix, int x, int y);
void			ft_scaling(float *matrix, float factor);
void			ft_changematrix(t_env *e);

/*
** ft_getgradient.c
*/
int				ft_getcolor(int *gradient, int *absolute, int z);
int				ft_color(int cola, int colb, int i, int size);
int				*ft_getgradient(int mode);

/*
** ft_getmap.c
*/
void			ft_colorpoints(t_map *map, int *gradient);
t_map			*ft_getmap(char *argv, t_env *e);

/*
** ft_scaleandcenter.c
*/
void			ft_scaletowindow(t_map *obj, t_env *e);
void			ft_center(t_map *obj, t_env *e);

/*
** ft_draw.c
*/
void			ft_draw(t_map *map, t_env *e);

/*
** ft_transformmap.c
*/
void			ft_transformmap(t_map *obj, t_env *e);

/*
** ft_applymatrix.c
*/
void			ft_getkey(int key, t_env *e);
void			ft_applymatrix(float *xyz, int *xy, float *matrix);

/*
** ft_fdfclean.c
*/
void			ft_fdfclean(t_env *e);

/*
** main.c
*/
void			ft_resetmatrixdata(t_env *e, t_matrix *matrix);
int				ft_expose_hook(t_env *e);
int				main(int argc, char **argv);

#endif
