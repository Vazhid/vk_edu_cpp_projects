#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "text_processing.hpp"
#include "tfidf_vectorization.hpp"

class Profile {};

class SimilarityCalculator {
 private:
 public:
   virtual void calculate() = 0;
   virtual double get_similarity() = 0;
};

class CosSimilarityCalculator : public SimilarityCalculator {
 private:
    std::vector<double> first_;
    std::vector<double> second_;
    double cos_similarity_;

 public:
   CosSimilarityCalculator() = default;
   CosSimilarityCalculator(std::vector<double> first, std::vector<double> second) 
      : first_(first),
        second_(second) {}
   
   void set_vectors(std::vector<double> first, std::vector<double> second);
   void calculate();
   double get_similarity();
};

struct User {
 public:
   explicit User(const Profile& profile);
   size_t id_;
   std::vector<double> text_vect_;
   std::vector<double> interest_vect_;
   double similarity;
   bool operator< (const User& p) const {
     return this->similarity < p.similarity;
   }
};

class Filter {
 private:
   User user_;
   std::vector<User> recommended_users_;

 public:
   void calculate_users_similiarity(CosSimilarityCalculator& cos_sim_calculator);
   void set_recommended_users(std::vector<User> recommended_users);
   std::vector<User> get_recommended_users();
};
