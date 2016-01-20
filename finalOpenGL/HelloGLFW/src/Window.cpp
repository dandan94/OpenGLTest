#include "Window.h"

Window::Window(const char* title, int width, int height)
{
    if(!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        glfwTerminate();
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


    mWindow = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), nullptr);
    if (mWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(mWindow);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return;
    }
}

void Window::update() const
{
    glfwPollEvents();
    glfwSwapBuffers(mWindow);
}

bool Window::shouldClose() const
{
    return glfwWindowShouldClose(mWindow);
}

Window::~Window()
{
    glfwTerminate();//dtor
}
