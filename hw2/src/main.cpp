#include "operations.hpp"
#include "commands_processing.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid numbers of arguments!" << std::endl;
        return 1;
    }
    
    std::vector<std::string> vect;
    auto string_of_commands = std::string(argv[1]);
    std::string line_sep = " | ";
    StrToVect(string_of_commands, line_sep, line_sep.length(), vect);

    std::vector<operation_t> vect_of_operations;
    std::vector<std::string> tmp;
    operation_t op;
    std::string space_sep = " ";

    for (size_t i = 0; i < vect.size(); i++) {
        StrToVect(vect[i], space_sep, space_sep.length(), tmp);
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

    std::vector<std::unique_ptr<IOperation>> vect_of_oper_ptr;

    for (operation_t operation : vect_of_operations) {
        if (operation.command == ECHO) {
            auto echo = std::make_unique<EchoOperation>(operation.first);
            vect_of_oper_ptr.push_back(std::move(echo));
        }
        if (operation.command == CAT) {
            auto cat = std::make_unique<CatOperation>(operation.first);
            vect_of_oper_ptr.push_back(std::move(cat));
        }
        if (operation.command == REPLACE) {
            auto replace = std::make_unique<ReplaceOperation>(operation.first, operation.second);
            vect_of_oper_ptr.push_back(std::move(replace));
        }
    }
    
    vect_of_oper_ptr[0]->ProcessLine(INITIAL_STR);
    vect_of_oper_ptr[0]->HandleEndOfInput();
    for (size_t i = 0; i < vect_of_operations.size() - 1; i++) {
        vect_of_oper_ptr[i]->SetNextOperation(*vect_of_oper_ptr[i + 1]);
    }
    
    return 0;
}