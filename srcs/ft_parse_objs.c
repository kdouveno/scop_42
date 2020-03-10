/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/03/10 16:42:36 by kdouveno         ###   ########.fr       */
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
void				test__print_parsed_obj_vbo(t_obj *t_obj);

t_obj				ft_parse_objs(char *path) // debug version of t_obj *ft_parse_objs: return type to restablish.
{
	t_obj_parsing	obj;
	FILE			*fd;
	char			*buf;
	size_t			capp;
	t_obj			out;

	obj = (t_obj_parsing){NULL, NULL, NULL, NULL, {}, {}, {}, NULL};
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
	// return (out);
}