#pragma once

#include <string>
#include <vector>
#include <map>

class Font {
    private:
        static std::map<char, std::vector<std::string>> mtxLet;

    public:
        static std::vector<std::string> mtxText(std::string text);
};