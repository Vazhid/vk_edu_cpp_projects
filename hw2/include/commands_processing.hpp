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

void StrSplitToVect(std::string& str, const std::string& sep, const int sep_len, std::vector <std::string>& str_vect);
void ParseArgument(const std::string& string_of_commands, std::vector<operation_t>& vect_of_operations);
void SetVectOfOperations(const std::vector<operation_t>& command_vect, std::vector<std::unique_ptr<IOperation>>& vect_of_operations);
