#include "operations.hpp"
#include "commands_processing.hpp"

int main(int argc, char *argv[]) {
    std::vector<std::pair<std::string,std::string>> vect_of_commands;
    auto first_arg = std::string(argv[1]);
    std::vector<std::string> all_args;

    GetArguments(first_arg, all_args, vect_of_commands);

    for (std::pair<std::string,std::string> pair : vect_of_commands) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    // std::string filename = "1.txt";

    // CatOperation cat(filename);
    // cat.ProcessLine("some text");

    // if (!cat.IsPerformed()) {
    //     std::cerr << "cat operation not performed" << std::endl;
    //     return 1;
    // }

    // EchoOperation echo("1");
    
    // cat.SetNextOperation(echo);

    // echo.SetNextOperation(cat);

    return 0;
}