#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height, const char *title);
    GLFWwindow* GetWindow() const { return window; };

    // Print specifications about the computer.
    void PrintSpecs();

    // Render scene on the window.
    void Render();

    // Generate object(s) to be drawn.
    void GenerateShaders();
private:
    int width, height;
    const char *title;
    GLFWwindow *window;

    // Shader stuff.
    unsigned int shaderProgram;
    unsigned int VBO, VAO;
};

#endif