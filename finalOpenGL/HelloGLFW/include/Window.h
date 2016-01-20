#ifndef WINDOW_H
#define WINDOW_H

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

#include "GLFW/glfw3.h"
#include <iostream>

class Window
{
    private:
        GLFWwindow* mWindow;
    public:
        Window(const char* title, int width, int height);
        virtual ~Window();
        bool shouldClose() const;
        void update() const;
};

#endif // WINDOW_H
