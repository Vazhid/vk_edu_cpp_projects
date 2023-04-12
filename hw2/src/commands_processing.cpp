#include "commands_processing.hpp"

void StrSplitToVect(std::string& str,
                    const std::string& sep,
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

void ParseArgument(const std::string& string_of_commands, std::vector<operation_t>& vect_of_operations) {
    std::string command_str = std::move(string_of_commands);
    std::vector<std::string> vect;
    std::vector<std::string> tmp;
    std::string line_sep = " | ";
    std::string space_sep = " ";
    operation_t op;

    StrSplitToVect(command_str, line_sep, line_sep.length(), vect);

    for (size_t i = 0; i < vect.size(); i++) {
        StrSplitToVect(vect[i], space_sep, space_sep.length(), tmp);
        if (tmp.size() == 2) {
            op.command = tmp[0];
            op.first = tmp[1];
        } else if (tmp.size() == 3) {
            op.command = tmp[0];
            op.first = tmp[1];
            op.second = tmp[2];
        }
        vect_of_operations.push_back(op);
        tmp.clear();
    }
}

void SetVectOfOperations(const std::vector<operation_t>& command_vect,
                         std::vector<std::unique_ptr<IOperation>>& oper_vect) {
    std::vector<operation_t> vect_of_commands = std::move(command_vect);
    for (operation_t operation : vect_of_commands) {
        if (operation.command == ECHO) {
            auto echo = std::make_unique<EchoOperation>(operation.first);
            oper_vect.push_back(std::move(echo));
        }
        if (operation.command == CAT) {
            auto cat = std::make_unique<CatOperation>(operation.first);
            oper_vect.push_back(std::move(cat));
        }
        if (operation.command == REPLACE) {
            auto replace = std::make_unique<ReplaceOperation>(operation.first, operation.second);
            oper_vect.push_back(std::move(replace));
        }
    }
}
