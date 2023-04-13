#include "operations.hpp"
#include "commands_processing.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Invalid numbers of arguments!" << std::endl;
        return 1;
    }

    auto string_of_commands = std::string(argv[1]);
    std::vector<operation_t> vect_of_commands;
    vect_of_commands = ParseArgument(string_of_commands);

    std::vector<std::unique_ptr<IOperation>> vect_of_operations;
    vect_of_operations = SetVectOfOperations(vect_of_commands);

    vect_of_operations[0]->ProcessLine(INITIAL_STR);
    vect_of_operations[0]->HandleEndOfInput();
    for (size_t i = 0; i < vect_of_operations.size() - 1; ++i) {
        vect_of_operations[i]->SetNextOperation(*vect_of_operations[i + 1]);
    }

    return 0;
}
