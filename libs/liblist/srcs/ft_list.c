/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:58:22 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/03 17:04:27 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"
#include <stdlib.h>

t_list			*ft_lst_add(t_list *begin, void *data)
{
	t_list		*out;

	if (!(out = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	*out = (t_list){begin, data};
	return (out);
}
