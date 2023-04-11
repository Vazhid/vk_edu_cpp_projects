#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#define ECHO "echo"
#define CAT "cat"
#define REPLACE "replace"
#define INITIAL_STR ""

struct operation_t {
    std::string command;
    std::string first;
    std::string second;
};

void StrToVect(std::string& str, std::string& sep, const int sep_len, std::vector <std::string>& str_vect);