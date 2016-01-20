#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>
#include <fstream>
#include <iostream>

class FileUtils
{
    private:
        FileUtils();
        virtual ~FileUtils();
    protected:
    public:
        static std::string read_file(const std::string &fileName);
};

#endif // FILEUTILS_H
