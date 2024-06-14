#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "window/window.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    Window myWindow(800, 600, "My OpenGL Window");

    if (myWindow.GetWindow() != NULL)
    {
        myWindow.PrintSpecs();
    }

    // Main loop
    while (!glfwWindowShouldClose(myWindow.GetWindow()))
    {
        processInput(myWindow.GetWindow());

        myWindow.GenerateShaders();
        myWindow.Render();

        glfwSwapBuffers(myWindow.GetWindow());
        glfwPollEvents();
    }

    // Clean up
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes.
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}