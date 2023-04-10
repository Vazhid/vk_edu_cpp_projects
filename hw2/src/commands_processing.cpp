#include "commands_processing.hpp"

void StrToVect(const std::string& str, char sep, std::vector <std::string>& str_vect) {
    std::string tmp_str;
    std::stringstream str_stream(str);

    while (str_stream) {
        getline(str_stream, tmp_str, sep);
        str_vect.push_back(tmp_str);
        tmp_str.clear();
    }   
}

void GetArguments(std::string& firs_arg, 
                  std::vector<std::string>& all_args, 
                  std::vector<std::pair<std::string,std::string>>& vect_of_commands) {
    
    std::pair<std::string, std::string> pair;
    StrToVect(firs_arg, ' ', all_args);

    for (size_t i = 0; i < all_args.size(); i++) {
        if (i % 2 == 0) {
            pair.first = all_args[i];
        } else {
            pair.second = all_args[i];
            vect_of_commands.push_back(pair);
        }
    }
}
