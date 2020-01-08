/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 08:21:47 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/08 15:37:47 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# define GL_SILENCE_DEPRECATION
//include <>
#include <stdbool.h>
// include ""

typedef struct	s_obj
{
	float		*vertices;
	unsigned	*indexes;
}				t_obj;

#endif