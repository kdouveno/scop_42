/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:58:22 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/06 12:52:13 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include <stdlib.h>


int			lst_push(t_list *begin, const void *data, const size_t data_size)
{
	t_list	out;

	if (!(out = malloc(sizeof(t_list) + data_size)))
		return (1);
	*(t_list*)*begin = *begin;
	memcpy(out, data, data_size + sizeof(t_list));
	*begin = out;
}

void		lst_set(t_list ptr, const void *data, const size_t data_size)
{
	memcpy(lst_elem(ptr), data, data_size);
}

void		lst_apnd(t_list *ptr, const void *data, const size_t data_size)
{
	t_list	out;

	if (!*ptr)
		lst_push(ptr, data, data_size);
	if (!(out = malloc(sizeof(t_list) + data_size)))
		return (1);
	*(t_list*)out = NULL;
	while (*(t_list*)*ptr != NULL)
	{
		*ptr = *(t_list*)*ptr;
	}
	*(t_list*)*ptr = out;
}