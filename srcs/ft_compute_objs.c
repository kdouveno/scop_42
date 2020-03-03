/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:10:17 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/03 16:44:53 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_obj.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include "../includes/scop.h"

void				each_compute_face(void *face, void *vbo)
{
	t_face_indices	*fi;

	fi = face;
}

t_obj				ft_compute_obj(t_obj_parsing	*obj)
{
	t_lsttab	vs;
	t_lsttab	vts;
	t_lsttab	vns;
	t_obj		out;

	BZ(out);
	if (!(out.faces_vbo = (t_face*)malloc(sizeof(t_face) * (lst_size(obj->f)))))
		error(DYNAMIC_ALLOCATION_ERROR);
	
	vs = lst_totab(obj->v, sizeof(t_vec));
	vts = lst_totab(obj->vt, sizeof(t_vec));
	vns = lst_totab(obj->vn, sizeof(t_vec));

}