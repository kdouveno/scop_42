/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:17:21 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/03 17:06:00 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/scop.h"
#include "../includes/test_globals.h"
#include "../includes/ft_parse_objs.h"
#include "../includes/ft_exits.h"
#include <string.h>

void	*ft_parse_line()
{

}

t_obj	*ft_parse_objs(char *path)
{
	t_obj	*out;
	FILE	*fd;
	char	*buf;

	if ((fd = fopen(path, "r")) == -1)
		error(OPEN_FILE_ERROR);
	buf = NULL;
	while (getLine(&buf, 0, fd) != -1)
	{
		ft_parse_line(buf);
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