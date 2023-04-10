#pragma once

#include <iostream>
#include <memory>
#include <fstream>

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
    bool performed_;

 public:
    explicit EchoOperation(const std::string& txt) 
        : text_(txt) {}

    std::string GetText();
    bool IsPerformed();  
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};

class CatOperation : public IOperation {
 private:
    const std::string& filename_;
    std::string text_;
    bool performed_;

 public:
    explicit CatOperation(const std::string& name) 
        : filename_(name) {}

    std::string GetFilename();
    std::string GetText();  
    bool IsPerformed();
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};

class ReplaceOperation : public IOperation {
 private:
    std::string replaceable_;
    std::string replacing_;
    std::string text_;
    bool performed_;

 public:
    explicit ReplaceOperation(const std::string& first, const std::string& second)
        : replaceable_(first),
          replacing_(second) {}

    std::string GetText();
    bool IsPerformed();  
    void ProcessLine(const std::string&) override;
    void HandleEndOfInput() override;
    void SetNextOperation(IOperation&) override;
};