#pragma once

#include <iostream>
#include <utility>
#include <functional>
#include <sstream>
#include <vector>
#include <getopt.h>

void GetArguments(std::string& firs_arg, 
                  std::vector<std::string>& all_args, 
                  std::vector<std::pair<std::string,std::string>>& vect_of_commands);

void StrToVect(const std::string& str, char sep, std::vector <std::string>& str_vect);