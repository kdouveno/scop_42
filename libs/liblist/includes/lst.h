/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:50:29 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/06 14:06:13 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>
# define LSTP(data) &data, sizeof(data)

typedef void* t_list;

int		lst_push(t_list *begin, const void *data, const size_t data_size);
int		lst_set(t_list ptr, const void *data, const size_t data_size);
int		lst_apnd(t_list *ptr, const void *data, const size_t data_size);

void	*lst_elem(t_list ptr);

#endif