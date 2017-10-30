#include "Game.h"

#include <algorithm>
#include "SOIL/SOIL.h"

Game::Game()
{
    m_Window = new Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);


    m_Mesh = Loader::loadOBJMesh("./res/models/bunny.obj");
    m_Shader = new Shader("./res/shaders/basicShader");

    m_Entities.push_back(new Model(m_Mesh, m_Shader, glm::vec3(5.0f, 0.0f, -2.0f)));

    int width, height;
    unsigned char* image = SOIL_load_image("./res/models/earth/4096_earth.jpg", &width, &height, 0, SOIL_LOAD_RGB);

    GLuint textureID;
    glGenTextures(1, &textureID);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Give the image to OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    m_Shader->setUniform1i("tex", 0);


    Camera* basicCamera = new Camera();
    basicCamera->setPosition(glm::vec3(0.0f, 0.0f, 3.0f));
    basicCamera->setFieldOfView(45.0f);
    basicCamera->setNearAndFarPlanes(1.0f, 1000.0f);
    basicCamera->setViewportAspectRatio((GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT);
    basicCamera->lookAt(glm::vec3(0.0f, 0.0f, 0.0f));

    m_Shader->setUniformMat4f("camera", basicCamera->getMatrix());
}


void Game::run()
{
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    GLfloat lastTime = glfwGetTime() * 1000;
    while(!m_Window->shouldClose())
    {
        GLfloat currentTime = glfwGetTime() * 1000;
        GLfloat delta = currentTime - lastTime;
        m_Window->update();

        update(delta);
        render();
        lastTime = currentTime;
    }
}

void Game::update(GLfloat delta)
{
    std::cout << 1000 /delta  <<  "fps" << std::endl;
    for(GLuint i = 0; i < m_Entities.size(); i++)
    {
        m_Entities[i]->update(delta);
    }
}

void Game::render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for(GLuint i = 0; i < m_Entities.size(); i++)
    {
        m_Entities[i]->render();
    }
}

Game::~Game()
{
    delete m_Shader;
    delete m_Window;
}
