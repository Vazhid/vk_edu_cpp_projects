#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "text_processing.hpp"

class IVectorizer {
 private: 
 public:
   virtual void vectorize(ITokenizer& tokenizer, IStemmer& stemmer) = 0;
   virtual std::vector<double> get_vect() = 0;
};

class VectorizerTFIDF : public IVectorizer {
 private:
  std::string text_;
  std::vector<double> vect_;
  std::string filename_;
  double tf_;
  double idf_;

  double calculate_TF(const std::string& word, const std::string& text);
  double calculate_IDF(std::string word, const std::string& filename);
  void tokenize_text(ITokenizer& tokenizer);
  void stemmize_text(IStemmer& stemmer);

 public:
  explicit VectorizerTFIDF(const std::string& text) : text_(text) {}
  VectorizerTFIDF() = default;
  void vectorize(ITokenizer& tokenizer, IStemmer& stemmer);
  void set_text(const std::string& text);
  void set_filename(const std::string& filename);
  std::vector<double> get_vect();
  double get_tf(const std::string& word);
  double get_idf(const std::string& word);
};
