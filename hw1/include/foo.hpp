#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <getopt.h>

enum search_box {
    PERSON_ID = 1,
    TITLE_ID = 2,
    TITLE_CHECK = 3,
    TITLE_NAME = 4
};

struct title_t {
    std::string id;
    std::string title_name;
    std::string title_type;
    bool is_movie();
};

struct person_t {
    std::string id;
    std::string primary_name;
    std::vector <title_t> titile_list;
};

struct arguments_t {
    std::string person_name;
    std::string person_surname;
    std::string filename_with_persons;
    std::string filename_with_titles_akas;
    std::string filename_with_titles_basics;
    std::string filename_with_actor_movie_link;
    bool is_full();
};

void get_arguments(int argc, char *argv[], arguments_t& args);

void search_field(std::istream& file, person_t& pers, search_box field);

void str_split(std::string& str, char sep, std::vector <std::string>& str_vect);