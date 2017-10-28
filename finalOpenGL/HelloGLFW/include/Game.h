#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Window.h"
#include "Shader.h"
#include "Mesh.h"
#include "Loader.h"
#include "Camera.h"
#include "StringUtils.h"
#include "MathUtils.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 480
#define WINDOW_TITLE "Testing OpenGL"

class Game
{
    private:
        Shader* m_Shader;
        Window* m_Window;
        Mesh* m_Mesh;
    private:
        void render();
        void update(GLfloat delta);
    public:
        Game();
        virtual ~Game();
        void run();
};

#endif // GAME_H
