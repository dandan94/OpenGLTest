#include "Loader.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tinyobjloader.h"

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

Mesh* Loader::loadOBJMesh(const string &fileName)
{
    vector<Vertex> vertices;
    vector<GLuint> indices;

    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;

    std::string err;
    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &err, fileName.c_str());

    if (!err.empty()) { // `err` may contain warning message.
      std::cerr << err << std::endl;
    }

    if (!ret) {
      exit(1);
    }
    Vertex currVertex;

    int i = 0;

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
      // Loop over faces(polygon)
      size_t index_offset = 0;
      for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
        int fv = shapes[s].mesh.num_face_vertices[f];

        // Loop over vertices in the face.
        for (size_t v = 0; v < fv; v++) {
          // access to vertex
          tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
          tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
          tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
          tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];


          tinyobj::real_t nx;
          tinyobj::real_t ny;
          tinyobj::real_t nz;

          if(idx.normal_index > 0)
          {
              nx = attrib.normals[3*idx.normal_index+0];
              ny = attrib.normals[3*idx.normal_index+1];
              nz = attrib.normals[3*idx.normal_index+2];
          }
          else
          {
              nx = 0.0f;
              ny = 0.0f;
              nz = 0.0f;
          }

          tinyobj::real_t tx;
          tinyobj::real_t ty;

          if(idx.texcoord_index > 0)
          {
              tx = attrib.texcoords[2*idx.texcoord_index+0];
              ty = attrib.texcoords[2*idx.texcoord_index+1];
          }
          else
          {
              tx = 0.0f;
              ty = 0.0f;
          }

          indices.push_back(i++);

          currVertex = {glm::vec3(vx, vy, vz), glm::vec3(nx, ny, nz), glm::vec2(tx, ty)};

          vertices.push_back(currVertex);
        }
        index_offset += fv;

        // per-face material
        shapes[s].mesh.material_ids[f];
      }
    }

    return new Mesh(vertices, indices);
}

Loader::~Loader()
{
    //dtor
}
