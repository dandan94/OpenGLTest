#include "Game.h"

#include <algorithm>
#include "./SOIL/SOIL.h"

Game::Game()
{
    m_Window = new Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    m_Shader = new Shader("./res/shaders/basicShader");

    m_Mesh = Loader::loadMesh("./res/models/bottle-a.obj");

    //int width, height;
    //unsigned char* image = SOIL_load_image("container.jpg", &width, &height, 0, SOIL_LOAD_RGB);


    glm::mat4 projectionMatrix = glm::perspective(45.0f, (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT, 0.1f, 1000.0f);

    m_Shader->setUniformMat4f("projection", projectionMatrix);
}


void Game::run()
{
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    while(!m_Window->shouldClose())
    {
        m_Window->update();
        update();
        render();
    }
}

void Game::update()
{

}

void Game::render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat timeValue = glfwGetTime();
    GLfloat radius = 1.0f;
    GLfloat x = sin(timeValue) * radius;
    GLfloat z = cos(timeValue) * radius;

    glm::mat4 transformationMatrix = MathUtils::createTransformationMatrix(glm::vec3(0.0f, 0.0f, -20.0f), glm::vec3(0.0f, x, 0.0f), 1.0f);
    m_Shader->setUniformMat4f("transform", transformationMatrix);
    m_Shader->setUniform4f("ourColor", glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    m_Shader->Bind();
    m_Mesh->render();
}

Game::~Game()
{
    delete m_Shader;
    delete m_Window;
    delete m_Mesh;
}
