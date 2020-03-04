/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:10:17 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/04 17:02:48 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_obj.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include "../includes/scop.h"
#include <string.h>
void				each_compute_face(void *face, void *data, int i)
{
	t_face_indices	*fi;
	t_obj_parsing	*obj;
	t_face			*cur;

	obj = data;
	fi = face;
	cur = obj->obj->faces_vbo + i;
	memcpy(cur, &obj->tv.tab[fi->v1], sizeof(t_vec));
	memcpy((void*)cur + sizeof(float) + 4, &obj->tv.tab[fi->vt1], sizeof(float) * 2);
	memcpy((void*)cur + sizeof(float) + 6, &obj->tv.tab[fi->vn1], sizeof(float) * 3);
	memcpy((void*)cur + sizeof(t_vertex), &obj->tv.tab[fi->v2], sizeof(t_vec));
	memcpy((void*)cur + sizeof(float) + 4, &obj->tv.tab[fi->vt2], sizeof(float) * 2);
	memcpy((void*)cur + sizeof(float) + 6, &obj->tv.tab[fi->vn2], sizeof(float) * 3);
	memcpy((void*)cur + sizeof(t_vertex) * 2, &obj->tv.tab[fi->v2], sizeof(t_vec));
	memcpy((void*)cur + sizeof(float) + 4, &obj->tv.tab[fi->vt3], sizeof(float) * 2);
	memcpy((void*)cur + sizeof(float) + 6, &obj->tv.tab[fi->vn3], sizeof(float) * 3);
}

t_obj				ft_compute_obj(t_obj_parsing	*obj)
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
	lst_each_di(obj->f, &each_compute_face, obj);
	return (out);
}