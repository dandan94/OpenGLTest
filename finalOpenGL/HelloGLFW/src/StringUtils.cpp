#include "StringUtils.h"

std::vector<std::string> StringUtils::split(const char* str, const char* delim)
{
    size_t strLen = strlen(str);
    char copyStr[strLen];
    strcpy(copyStr, str);

    char *token = strtok(copyStr, delim);
    std::vector<std::string> tokenArr;

    while(token)
    {
        tokenArr.push_back(token);

        token = strtok(NULL, delim);
    }

    return tokenArr;
}
