#include "FileUtils.h"

FileUtils::FileUtils()
{

}

FileUtils::~FileUtils()
{

}

std::string FileUtils::read_file(const std::string &fileName)
{
    std::string line;
    std::string file_contents;
    std::ifstream fileHandle (fileName.c_str());
    if (fileHandle.is_open())
    {
        while ( getline (fileHandle,line) )
        {
            file_contents += line;
            file_contents.push_back('\n');
        }
        fileHandle.close();
    }
    else
    {
        std::cout<<"There was an error loading the file "<<fileName<<std::endl;
    }

    return file_contents;
}
