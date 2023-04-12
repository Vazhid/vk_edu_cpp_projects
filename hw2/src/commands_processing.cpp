// Copyright 2023 Vazhid

#include "commands_processing.hpp"

void StrToVect(std::string& str,
               std::string& sep,
               const int sep_len,
               std::vector <std::string>& str_vect) {
    std::string str_tmp = std::move(str);
    int end = str_tmp.find(sep);
    while (end != -1) {
        str_vect.push_back(str_tmp.substr(0, end));
        str_tmp.erase(str_tmp.begin(), str_tmp.begin() + end + sep_len);
        end = str_tmp.find(sep);
    }
    str_vect.push_back(str_tmp.substr(0, end));
}
