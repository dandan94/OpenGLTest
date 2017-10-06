#include "Loader.h"

using namespace std;

Loader::Loader()
{
    //ctor
}

Mesh* Loader::loadMesh(const string &fileName)
{
    string fileContents = FileUtils::read_file(fileName);

    vector<string> lines = StringUtils::split(fileContents.c_str(), "\n");
    vector<Vertex> positions;
    vector<GLuint> indices;
    vector<glm::vec3> normals;

    int firstFaceIndex = 0;

    //vector<GLfloat> textureArray;
    vector<glm::vec3> sortedNormals;


    for(int i=0;i<lines.size();i++)
    {
        string line = lines[i];
        if(line == "") continue;

        vector<string> parts = StringUtils::split(line.c_str(), " ");

        if(parts[0] == "#") continue;

        if(parts[0] == "v")
        {
            glm::vec3 currentPos = glm::vec3((GLfloat) atof(parts[1].c_str()), (GLfloat) atof(parts[2].c_str()), (GLfloat) atof(parts[3].c_str()));
            Vertex currVertex;
            currVertex.Position = currentPos;
            positions.push_back(currVertex);
        }
        else if(parts[0] == "vn")
        {
            glm::vec3 currentNormal = glm::vec3((GLfloat) atof(parts[1].c_str()), (GLfloat) atof(parts[2].c_str()), (GLfloat) atof(parts[3].c_str()));
            normals.push_back(currentNormal);
        }
        else if(parts[0] == "f")
        {
            vector<string> vertex1 = StringUtils::split(parts[1].c_str(), "/");
            vector<string> vertex2 = StringUtils::split(parts[2].c_str(), "/");
            vector<string> vertex3 = StringUtils::split(parts[3].c_str(), "/");

            indices.push_back((GLuint) atoi(vertex1[0].c_str()) - 1);
            indices.push_back((GLuint) atoi(vertex2[0].c_str()) - 1);
            indices.push_back((GLuint) atoi(vertex3[0].c_str()) - 1);

            if(vertex1.size() > 2 && vertex2.size() > 2 && vertex3.size() > 2)
            {
                GLuint normalIndex = (GLuint) atoi(vertex1[2].c_str());

                positions[normalIndex].Normal = normals[normalIndex];
            }
        }
    }

    Mesh* mesh;

    if(sortedNormals.size() > 0)
    {
        //mesh = new Mesh(vertices, indices, sortedNormals);
    }
    else
    {
        mesh = new Mesh(positions, indices);
    }

    return mesh;
}

Loader::~Loader()
{
    //dtor
}
