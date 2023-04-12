// Copyright 2023 Vazhid

#pragma once

#include <iostream>
#include <fstream>
#include <memory>
#include <regex>

class IOperation {
 private:
 public:
    virtual void ProcessLine(const std::string&) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation&) = 0;
};

class EchoOperation : public IOperation {
 private:
    std::string text_;

 public:
    EchoOperation() : text_("") {}
    explicit EchoOperation(const std::string& txt) 
      : text_(txt) {}
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};

class CatOperation : public IOperation {
 private:
    std::string filename_;
    std::string text_;

 public:
    explicit CatOperation(std::string name) 
      : filename_(name) {}
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};

class ReplaceOperation : public IOperation {
 private:
    std::string replaceable_;
    std::string replacing_;
    std::string text_;

 public:
    explicit ReplaceOperation(const std::string& first, const std::string& second)
      : replaceable_(first),
        replacing_(second) {}
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};