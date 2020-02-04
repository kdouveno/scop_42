/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:58:22 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/04 17:04:09 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include <stdlib.h>

int		ft_lst_push(t_list *begin, const void *data, const size_t data_size)
{
	t_list	out;
	t_list	*next;

	if (!(out = malloc(sizeof(t_list) + data_size)))
		return (1);
	memcpy(out, data, data_size);
	next = (t_list*)out + data_size;
	*next = *begin;
	*begin = out;
}
