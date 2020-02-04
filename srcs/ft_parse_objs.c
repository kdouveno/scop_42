/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/04 16:21:04 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../includes/test_globals.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include <string.h>

static inline void	*ft_parse_vertex(char *cmd, t_obj_parsing *obj)
{
	t_veclist	*vec;

	if (!(vec = (t_veclist*)malloc(sizeof(t_veclist)))
		error(DYNAMIC_ALLOCATION_ERROR);
	
}

static inline void	*ft_parse_line(char *buf, t_obj_parsing *obj)
{
	char	*tmp;
	t_vec	vec;
	if ((tmp = strtok(buf, " ")))
	{
		if (tmp[0] == 'v')
			ft_parse_vertex(tmp, obj);
	}
}

t_obj	*ft_parse_objs(char *path)
{
	t_obj_parsing	out;
	FILE			*fd;
	char			*buf;

	out = (t_obj_parsing){NULL, NULL, NULL, NULL};
	if ((fd = fopen(path, "r")) == -1)
		error(OPEN_FILE_ERROR);
	buf = NULL;
	while (getLine(&buf, 0, fd) != -1)
	{
		ft_parse_line(buf, &out);
		free(buf);
		buf = NULL;
	}
	// t_obj out;


	// out.vertices = g_vertices;
	// out.v_size = sizeof(g_vertices);
	// out.indices = g_indices;
	// out.i_size = sizeof(g_indices);
	return (out);
}