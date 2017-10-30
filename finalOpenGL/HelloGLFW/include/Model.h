#ifndef MODEL_H
#define MODEL_H

#include <Entity.h>


class Model : public Entity
{
    public:
        Model(Mesh *mesh, Shader* shader, const glm::vec3 &position);
        virtual ~Model();
        glm::vec3 GetPosition() { return m_Position; }
        void SetPosition(glm::vec3 val) { m_Position = val; }
        Mesh* getMesh() { return m_Mesh; }
        void setMesh(Mesh* val) { m_Mesh = val; }
        Shader* getShader() { return m_Shader; }
        void setShader(Shader* val) { m_Shader = val; }

        void update(GLfloat delta) override;
        void render() override;
    protected:
    private:
        glm::vec3 m_Position;
        Mesh* m_Mesh;
        Shader* m_Shader;
};

#endif // MODEL_H
