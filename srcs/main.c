#include "../includes/scop.h"
#include "../includes/ft_glfw.h"
#include "../includes/ft_exits.h"
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



int main(int argc, char **argv)
{
	t_obj		*obj;
	void		*win;

	if (argc != 2)
		usage();
	ft_glfw_init();
	if ((win = ft_glfw_new_window_context())
		&& ft_glfw_init_glad())
	{
		obj = ft_parse_objs(argv[1]);
		ft_parse_shaders(&obj);
		ft_load_shaders(&obj);
		ft_load_objs(&obj);
		ft_gl_loop(win, &ft_loop, &obj);
	}
	else
		return (-1);
	return (0);
}



// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
