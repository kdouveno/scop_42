/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/02 17:11:37 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../includes/test_globals.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include "../libs/liblst/includes/lst.h"
#include <string.h>
#include <stdio.h>

static inline void	ft_parse_vertex(char *cmd, t_obj_parsing *obj)
{
	t_vec	vertex;
	char	*tmp;

	vertex.a = atof(strtok(NULL, " "));
	vertex.b = atof(strtok(NULL, " "));
	vertex.c = atof(strtok(NULL, " "));
	tmp = strtok(NULL, " ");
	vertex.d = tmp ? atof(tmp) : 1.0f;
	if (!cmd[1])
		lst_push(obj->v, LSTP(vertex));
	else if (cmd[1] == 't' && !cmd[2])
		lst_push(obj->vt, LSTP(vertex));
	else if (cmd[1] == 'n' && !cmd[2])
		lst_push(obj->vn, LSTP(vertex));
	else
		error(OBJ_FILE_ERROR);
}


static inline void	ft_parse_index(t_obj_parsing *obj)
{
	char			*tmp;
	int				faces[9];
	int				i;

	i = 0;
	while (i < 9)
	{
		tmp = strtok(NULL, " ");
		faces[i++] = atoi(tmp);
		while (*tmp && *tmp != '/')
			tmp++;
		faces[i++] == *tmp ? atoi(tmp++ + 1) : 0;
		while (*tmp && *tmp != '/')
			tmp++;
		faces[i++] == *tmp ? atoi(tmp++ + 1) : 0;
	}

	lst_push(obj->f, LSTP(faces));
}

static inline void	ft_parse_line(char *buf, t_obj_parsing *obj)
{
	char	*tmp;

	if ((tmp = strtok(buf, " ")))
	{

		if (tmp[0] == 'v')
			ft_parse_vertex(tmp, obj);
		else if (tmp[0] == 'f')
			ft_parse_index(obj);
	}
}

void				each_print_vector(void *ptr, size_t index){
	t_vec	*vec;

	(void)index;
	vec = (t_vec*)ptr;
	printf("%f %f %f %f\n", vec->a, vec->b, vec->c, vec->d);
}
void				each_print_indices(void *ptr, size_t index){
	t_face_indices	*indices;

	(void)index;
	indices = (t_face_indices*)ptr;
	printf("f %d/%d/%d %d/%d/%d %d/%d/%d\n",
			indices->v1,
			indices->vt1,
			indices->vn1,
			indices->v2,
			indices->vt2,
			indices->vn2,
			indices->v3,
			indices->vt3,
			indices->vn3
	);
}

void				test__print_parse_obj(t_obj_parsing *obj)
{
	printf("v ");
	lst_each(obj->v, &each_print_vector);
	printf("vt ");
	lst_each(obj->vt, &each_print_vector);
	printf("vn ");
	lst_each(obj->vn, &each_print_vector);
	lst_each(obj->f, &each_print_indices);
}

void				ft_parse_objs(char *path) // debug version of t_obj *ft_parse_objs: return type to restablish.
{
	t_obj_parsing	out;
	FILE			*fd;
	char			*buf;
	size_t			capp;

	out = (t_obj_parsing){NULL, NULL, NULL, NULL};
	if ((fd = fopen(path, "r")) == NULL)
		error(OPEN_FILE_ERROR);
	buf = NULL;
	capp = 0;
	while (getline(&buf, &capp, fd) > 0)
	{
		ft_parse_line(buf, &out);
		free(buf);
		buf = NULL;
	}
	test__print_parse_obj(&out);
	// return (out);
}