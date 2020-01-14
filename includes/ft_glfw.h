/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glfw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:28:05 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/11 17:32:23 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_GLFW_H
#define FL_GLFW_H


#include "../libs/glad/includes/glad.h"
#include "glfw3.h"
// settings
static const unsigned int SCR_WIDTH = 800;
static const unsigned int SCR_HEIGHT = 600;

void		ft_glfw_init();
GLFWwindow*	ft_glfw_new_window_context();
int			ft_glfw_init_glad();
void		ft_gl_loop(GLFWwindow *window, void (*inloop)(void*), void *data);

#endif // FL_GLFW_H
