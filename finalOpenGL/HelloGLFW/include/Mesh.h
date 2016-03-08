#ifndef MESH_H
#define MESH_H


#define GLEW_STATIC
#include <GL/glew.h>

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Shader.h"

using namespace std;

class Mesh
{
    public:
        vector<Vertex> vertices;
        vector<GLuint> indices;
        Mesh(vector<Vertex> vertices, vector<GLuint> indices);
        //Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices, std::vector<GLfloat> normals);
        virtual ~Mesh();
        void render(Shader* shader);
    private:
        GLuint VAO, VBO, EBO;
        void setup();
};

#endif // MESH_H
