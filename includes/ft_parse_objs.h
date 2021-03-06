/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_objs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karldouvenot <karldouvenot@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:38:54 by kdouveno          #+#    #+#             */
/*   Updated: 2020/04/27 16:49:47 by karldouveno      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_OBJS_H
# define FT_PARSE_OBJS_H
# include "../libs/libmatrix/includes/ft_gl.h"
# include "ft_obj.h"
# include "../libs/liblst/includes/lst.h"
# define BUF_SIZE 64



typedef struct			s_obj_parsing
{
	t_obj				*obj;
	t_list				v;
	t_list				vt;
	t_list				vn;
	t_lsttab			tv;
	t_lsttab			tvt;
	t_lsttab			tvn;
	t_list				f;
}						t_obj_parsing;

t_obj					ft_parse_objs(char *path);

t_obj					ft_compute_obj(t_obj_parsing *obj);

#endif