/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karldouvenot <karldouvenot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/06/11 13:19:09 by karldouveno      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../includes/test_globals.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include "../libs/liblst/includes/lst.h"
#include <string.h>
#include <stdio.h>

void				test__print_parsed_obj_vbo(t_obj *t_obj);

void				test__print_reved_lst(void *data)
{
	t_vec	vertex;

	vertex = *(t_vec*)data;
	printf("%f, %f, %f\n", vertex.a, vertex.b, vertex.c);
}

void				test__print_reved_faces_indices(void *data)
{
	t_face_indices	fi;

	fi = *(t_face_indices*)data;
	printf("%d/%d/%d %d/%d/%d %d/%d/%d\n", fi.v1, fi.vt1, fi.vn1, fi.v2, fi.vt2, fi.vn2, fi.v3, fi.vt3, fi.vn3);
}

static inline void	ft_parse_vertex(char *cmd, t_obj_parsing *obj)
{
	t_vec	vertex;

	vertex.a = atof(strtok(NULL, " "));
	vertex.b = atof(strtok(NULL, " "));
	vertex.c = atof(strtok(NULL, " "));
	if (!cmd[1])
		lst_push(&obj->v, LSTP(vertex));
	else if (cmd[1] == 't' && !cmd[2])
		lst_push(&obj->vt, LSTP(vertex));
	else if (cmd[1] == 'n' && !cmd[2])
		lst_push(&obj->vn, LSTP(vertex));
	else
		error(OBJ_FILE_ERROR);
}


static inline void	ft_parse_index(t_obj_parsing *obj)
{
	char			*tmp;
	int				faces[9];
	int				i;

	i = 0;
	bzero(faces, sizeof(faces));
	while (i < 9)
	{
		tmp = strtok(NULL, " ");
		if (!tmp)
			break ;
		faces[i++] = atoi(tmp);
		while (*tmp && tmp[-1] != '/')
			tmp++;
		faces[i++] = atoi(tmp++);
		while (*tmp && tmp[-1] != '/')
			tmp++;
		faces[i++] = atoi(tmp++);
	}
	lst_push(&obj->f, LSTP(faces));
}

static inline void	ft_parse_line(char *buf, t_obj_parsing *obj)
{
	char	*tmp;

	tmp = strtok(buf, " ");
	if (tmp)
	{
		if (tmp[0] == 'v')
			ft_parse_vertex(tmp, obj);
		else if (tmp[0] == 'f')
			ft_parse_index(obj);
		tmp = strtok(NULL, " ");
	}
}

t_obj_parsing		ft_init_parse_obj()
{
	t_obj_parsing	out;
	t_vec			model;

	model = (t_vec){0, 0, 0, 0};
	out = (t_obj_parsing){NULL, NULL, NULL, NULL, {}, {}, {}, NULL};
	lst_push(&out.v, LSTP(model));
	lst_push(&out.vt, LSTP(model));
	lst_push(&out.vn, LSTP(model));
	return out;
}

t_obj				ft_parse_objs(char *path) // debug version of t_obj *ft_parse_objs: return type to restablish.
{
	t_obj_parsing	obj;
	FILE			*fd;
	char			*buf;
	size_t			capp;
	t_obj			out;

	obj = ft_init_parse_obj();
	if ((fd = fopen(path, "r")) == NULL)
		error(OPEN_FILE_ERROR);
	buf = NULL;
	capp = 0;
	while (getline(&buf, &capp, fd) > 0)
	{
		ft_parse_line(buf, &obj);
		free(buf);
		buf = NULL;
	}
	lst_rev(&obj.f);
	lst_rev(&obj.v);
	lst_rev(&obj.vt);

	lst_rev(&obj.vn);
	out = ft_compute_obj(&obj);
	test__print_parsed_obj_vbo(&out);
	return (out);
}