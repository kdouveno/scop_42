/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karldouvenot <karldouvenot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:10:17 by kdouveno          #+#    #+#             */
/*   Updated: 2020/06/11 13:15:59 by karldouveno      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_obj.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include "../includes/scop.h"
#include <string.h>
void				each_compute_face(void *face, void *data, size_t i)
{
	t_face_indices	*fi;
	t_obj_parsing	*obj;
	t_face			*cur;

	obj = data;
	fi = face;
	cur = obj->obj->faces_vbo + i;
	memcpy(cur, (t_vec*)obj->tv.tab + fi->v1, SOF * 3);
	memcpy((float*)cur + 3, (t_vec*)obj->tvt.tab + fi->vt1, SOF * 2);
	memcpy((float*)cur + 5, (t_vec*)obj->tvn.tab + fi->vn1, SOF * 3);

	memcpy((float*)cur + 8, (t_vec*)obj->tv.tab + fi->v2, SOF * 3);
	memcpy((float*)cur + 11, (t_vec*)obj->tvt.tab + fi->vt2, SOF * 2);
	memcpy((float*)cur + 13, (t_vec*)obj->tvn.tab + fi->vn2, SOF * 3);
	
	memcpy((float*)cur + 16, (t_vec*)obj->tv.tab + fi->v3, SOF * 3);
	memcpy((float*)cur + 19, (t_vec*)obj->tvt.tab + fi->vt3, SOF * 2);
	memcpy((float*)cur + 21, (t_vec*)obj->tvn.tab + fi->vn3, SOF * 3);
}

t_obj				ft_compute_obj(t_obj_parsing *obj)
{
	t_obj		out;

	BZERO(out);
	obj->obj = &out;
	out.faces_size = lst_size(obj->f);
	if (!(out.faces_vbo = (t_face*)malloc(sizeof(t_face) * out.faces_size)))
		error(DYNAMIC_ALLOCATION_ERROR);
	obj->tv = lst_totab(obj->v, sizeof(t_vec));
	obj->tvt = lst_totab(obj->vt, sizeof(t_vec));
	obj->tvn = lst_totab(obj->vn, sizeof(t_vec));
	if (!(obj->tv.tab && obj->tvt.tab && obj->tvn.tab))
		error(DYNAMIC_ALLOCATION_ERROR);
	lst_each_di(obj->f, &each_compute_face, obj);
	return (out);
}