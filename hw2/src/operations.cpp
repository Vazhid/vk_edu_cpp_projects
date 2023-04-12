#include "operations.hpp"

void EchoOperation::ProcessLine(const std::string& str) {}

void EchoOperation::HandleEndOfInput() {
    std::cout << text_ << std::endl;
}

void EchoOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(text_);
    operation.HandleEndOfInput();
}

void CatOperation::ProcessLine(const std::string& str) {
    text_ = std::move(str);
}

void CatOperation::HandleEndOfInput() {
    std::string str_input;
    std::ifstream file{filename_};

    if (!file.is_open()) {
        std::cerr
            << filename_
            << " could not be opened for reading!"
            << std::endl;
    }

    while (getline(file, str_input)) {
        text_ += "\n" + str_input;
        std::cout << str_input << std::endl;
        str_input.clear();
    }
}

void CatOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(text_);
    operation.HandleEndOfInput();
}

void ReplaceOperation::ProcessLine(const std::string& str) {
    text_ = std::move(str);
}

void ReplaceOperation::HandleEndOfInput() {
    text_ = std::regex_replace(text_, std::regex(replaceable_), replacing_);
    std::cout << text_ << std::endl;
}

void ReplaceOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(text_);
}
