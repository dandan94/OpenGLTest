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
    vector<glm::vec3> positions;
    vector<GLuint> indices;
    vector<glm::vec3> normals;

    int firstFaceIndex = 0;

    //vector<GLfloat> textureArray;
    vector<GLfloat> sortedNormals;


    for(int i=0;i<lines.size();i++)
    {
        string line = lines[i];
        if(line == "") break;

        vector<string> parts = StringUtils::split(line.c_str(), " ");

        if(parts[0] == "#") continue;

        if(parts[0] == "v")
        {
            glm::vec3 currentPos = glm::vec3((GLfloat) atof(parts[1].c_str()), (GLfloat) atof(parts[2].c_str()), (GLfloat) atof(parts[3].c_str()));
            positions.push_back(currentPos);
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
                GLuint normal1Index = (GLuint) atoi(vertex1[2].c_str());
                GLuint normal2Index = (GLuint) atoi(vertex2[2].c_str());
                GLuint normal3Index = (GLuint) atoi(vertex3[2].c_str());

                sortedNormals.push_back(normals[normal1Index - 1]);
            }
        }
    }

    Mesh* mesh;

    if(sortedNormals.size() > 0)
    {
        mesh = new Mesh(vertices, indices, sortedNormals);
    }
    else
    {
        mesh = new Mesh(vertices, indices);
    }

    return mesh;
}

Loader::~Loader()
{
    //dtor
}
