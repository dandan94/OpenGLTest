#ifndef LOADER_H
#define LOADER_H

#include "Mesh.h"
#include "FileUtils.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include "StringUtils.h"
#include <vector>
#include <boost/algorithm/string.hpp>

class Loader
{
    public:
        Loader();
        virtual ~Loader();
        static Mesh* loadMesh(const std::string &fileName);
        static Mesh* loadOBJMesh(const string &fileName);
    protected:
    private:
};

#endif // LOADER_H
