/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:41:59 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/26 19:30:52 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlistreverse(t_dlist *lst)
{
	t_dbl		*tmp;
	t_dbl		*swap;

	if (lst != NULL && (tmp = lst->head) != NULL)
	{
		swap = lst->head;
		lst->head = lst->tail;
		lst->tail = swap;
		while (tmp != NULL)
		{
			swap = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = swap;
			tmp = tmp->next;
		}
	}
}

t_list		*ft_lstreverse(t_list *data, t_list *next)
{
	t_list		*tmp;

	if (next == NULL)
		return (data);
	tmp = next->next;
	next->next = data;
	if ((void *)data->next == (void *)next)
		data->next = NULL;
	if (tmp != NULL)
		return (ft_lstreverse(next, tmp));
	return (next);
}
