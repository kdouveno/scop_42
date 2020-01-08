#include "../includes/scop.h"
#include "../includes/ft_glfw.h"
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);



void ft_load_model(){
	ft_parse_obj();
}

int main()
{
	void		ft_init_glfw();
	GLFWwindow*	ft_glfw_new_window_context();
	if (ft_glfw_init_glad())
		return -1;
	ft_load_model();
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
