#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>
#include <cstring>
#include <iostream>


class StringUtils
{
    public:
        static std::vector<std::string> split(const char* str, const char* delim);
    protected:
    private:
};

#endif // STRINGUTILS_H
