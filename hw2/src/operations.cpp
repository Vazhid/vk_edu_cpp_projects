#include "operations.hpp"

void EchoOperation::ProcessLine(const std::string& str) {
    std::cout << text_ << std::endl;;
    HandleEndOfInput();
}

void EchoOperation::HandleEndOfInput() {
    performed_ = true;
}

void EchoOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(text_);
}

std::string EchoOperation::GetText() {
    return text_;
}

bool EchoOperation::IsPerformed() {
    return performed_;
}


void CatOperation::ProcessLine(const std::string& str) {
    text_ = std::move(str);
    
    std::string str_input;
    std::ifstream file{filename_};

    if (!file.is_open()) {
        std::cerr << filename_ << " could not be opened for reading!" << std::endl;
    }

    while (file) {
        getline(file, str_input, '\n');
        text_ += "\n" + str_input;
        std::cout << str_input << std::endl;
        str_input.clear();
    }

    HandleEndOfInput();
}

void CatOperation::HandleEndOfInput() {
    performed_ = true;
}

void CatOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(std::move(text_));
}

std::string CatOperation::GetFilename() {
    return filename_;
}

std::string CatOperation::GetText() {
    return text_;
}

bool CatOperation::IsPerformed() {
    return performed_;
}


void ReplaceOperation::ProcessLine(const std::string& str) {

}

void ReplaceOperation::HandleEndOfInput() {
    performed_ = true;
}

void ReplaceOperation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(text_);
}

std::string ReplaceOperation::GetText() {
    return text_;
}


bool ReplaceOperation::IsPerformed() {
    return performed_;
}