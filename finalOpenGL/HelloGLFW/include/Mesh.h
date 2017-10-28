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
        Mesh(const vector<Vertex> &vertices, const vector<GLuint> &indices);
        virtual ~Mesh();
        void render();
    private:
        GLuint VAO, VBO, EBO;
        vector<Vertex> vertices;
        vector<GLuint> indices;
};

#endif // MESH_H
