/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoudan <msoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:31:10 by msoudan           #+#    #+#             */
/*   Updated: 2016/02/25 21:06:29 by msoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_error(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror(str);
	return (-1);
}

void		*ft_errornull(char *str)
{
	if (str)
		ft_putendl_fd(str, STDERR_FILENO);
	else
		perror(str);
	return (NULL);
}
