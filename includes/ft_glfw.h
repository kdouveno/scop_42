/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glfw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdouveno <kdouveno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:28:05 by kdouveno          #+#    #+#             */
/*   Updated: 2020/01/08 14:53:29 by kdouveno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_GLFW_H
#define FL_GLFW_H

#include "glfw3.h"
#include "../libs/glad/includes/glad.h"

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void		ft_init_glfw();
GLFWwindow*	ft_glfw_new_window_context();
void		ft_glwf_init_glad();

#endif // FL_GLFW_H
