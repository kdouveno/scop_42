/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:38:54 by kdouveno          #+#    #+#             */
/*   Updated: 2020/02/04 13:48:39 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_OBJS_H
# define FT_PARSE_OBJS_H
# include "../libs/libmatrix/includes/ft_gl.h"
# include "ft_obj.h"
# include "../libs/liblist/includes/ft_list.h"
# define BUF_SIZE 64



typedef struct			s_veclist
{
	struct s_veclist	*next;
	t_vec				vec;
}						t_veclist;

typedef struct			s_obj_parsing
{
	t_veclist			*v;
	t_veclist			*vt;
	t_veclist			*vn;
	t_face_indices		*f;
}						t_obj_parsing;

t_obj					*ft_parse_objs(char *path);

#endif