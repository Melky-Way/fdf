/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:36:38 by msoudan           #+#    #+#             */
/*   Updated: 2016/03/17 19:19:50 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#define BIGGER (abs[0] < vertex->xyz[2])
#define LOWER (abs[1] > vertex->xyz[2])
#define TRANSL_X (e->width - map->xy[0]) / 2
#define TRANSL_Y (e->height - map->xy[1]) / 2
#define T_VECTOR_NEXT ((t_vector *)tmp->next->content)

static int		ft_getdata(int *abs, char *line, t_dlist *data, int y)
{
	char		**array;
	t_vector	*vertex;
	int			x;

	if ((array = ft_strsplit(line, ' ')) == NULL)
		return (ft_error("Malloc failed on ft_strsplit."));
	x = -1;
	abs[0] = !y ? ft_atoi(array[x + 1]) : abs[0];
	abs[1] = !y ? ft_atoi(array[x + 1]) : abs[1];
	while (array[++x])
	{
		if ((vertex = malloc(sizeof(t_vector))) == NULL)
			return (ft_error("Malloc failed on t_vector object."));
		vertex->xyz[0] = x * 10;
		vertex->xyz[1] = y * 10;
		vertex->xyz[2] = ft_atoi(array[x]);
		abs[0] = BIGGER ? vertex->xyz[2] : abs[0];
		abs[1] = LOWER ? vertex->xyz[2] : abs[1];
		ft_dlist_tail(data, vertex, sizeof(t_vector));
	}
	ft_arrdel(&array);
	return (0);
}

static int		ft_spaceordigit(char *str)
{
	int			i;

	i = 0;
	while (str != NULL && str[i] && \
		(ft_isspace(str[i]) || ft_isdigit(str[i]) || str[i] == '-'))
		i++;
	return (str[i]);
}

static t_dlist	*get_mapdata(int *abs, char *argv)
{
	char		*line;
	int			fd;
	t_dlist		*data;
	int			i;

	i = -1;
	data = ft_dlist_new();
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (ft_errornull("Cannot open specified map."));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_spaceordigit(line))
		{
			free(line);
			close(fd);
			return (ft_errornull("Incorrect map."));
		}
		ft_getdata(abs, line, data, ++i);
		free(line);
	}
	close(fd);
	return (data);
}

t_map			*ft_getmap(char *argv, t_env *e)
{
	t_map		*map;

	if ((map = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	if ((map->coord = get_mapdata(map->absolute, argv)) == NULL)
		return (ft_errornull("get_mapdata failed."));
	map->xy[0] = ((t_vector *)map->coord->tail->content)->xyz[0];
	map->xy[1] = ((t_vector *)map->coord->tail->content)->xyz[1];
	ft_colorpoints(map, e->gradient);
	return (map);
}
