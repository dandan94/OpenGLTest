#include "Model.h"

Model::Model(Mesh* mesh, Shader* shader, const glm::vec3 &position):
m_Mesh(mesh), m_Shader(shader), m_Position(position)
{
    glm::mat4 transformationMatrix = MathUtils::createTransformationMatrix(m_Position, glm::vec3(0.0f, 0.0f, 0.0f), 1.0f);
    m_Shader->setUniformMat4f("model", transformationMatrix);
}

void Model::update(GLfloat delta)
{

}

void Model::render()
{
    m_Shader->Bind();
    m_Mesh->render();
}

Model::~Model()
{
    //dtor
}
