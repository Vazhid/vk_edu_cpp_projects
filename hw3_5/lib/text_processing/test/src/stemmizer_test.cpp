#include <gtest/gtest.h>
#include "text_processing.hpp"

TEST(PortersStemmerTest, StemmizeTest) {
    PortersStemmer stemmer({"Каждый", "охотник", "желает", "знать"});
    stemmer.stemmize();
    std::vector<std::string> expect_stems {"Кажд", "охотн", "жел", "знат"};
    EXPECT_EQ(stemmer.get_stems(), expect_stems);
}
