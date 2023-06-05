#pragma once

#include <iostream>
#include <sstream>
#include <memory>
#include <vector>

#include "operations.hpp"

#define ECHO "echo"
#define CAT "cat"
#define REPLACE "replace"
#define INITIAL_STR ""

struct operation_t {
    std::string command;
    std::string first;
    std::string second;
};

std::vector<std::string> StrSplitToVect(const std::string& str, const std::string& sep, const int sep_len);
std::vector<operation_t> ParseArgument(const std::string& string_of_commands);
std::vector<std::unique_ptr<IOperation>> SetVectOfOperations(const std::vector<operation_t>& command_vect);