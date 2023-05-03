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

   double calculate_TF(std::string word, const std::string& text);
   double calculate_IDF(std::string word, const std::string& filename);
   void tokenize_text(ITokenizer& tokenizer);
   void stemmize_text(IStemmer& stemmer);

 public:
   void vectorize(ITokenizer& tokenizer, IStemmer& stemmer);
   std::vector<double> get_vect();
};
