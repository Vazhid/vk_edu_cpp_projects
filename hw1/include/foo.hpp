#pragma once

#include <vector>
#include <iostream>

enum search_box {
    PERSON_ID = 1,
    TITLE_ID = 2,
    TITLE_CHECK = 3,
    TITLE_NAME = 4
};

struct title_t {
    std::string title_name;
    std::string title_type;
    std::string id;
    bool is_movie() {
        return (title_type == "movie") ? true : false;
    }
};

struct person_t {
    std::string primary_name;
    std::string id;
    std::vector <title_t> titile_list;
};

struct arguments_t {
    std::string person_name;
    std::string person_surname;
    std::string filename_with_persons;
    std::string filename_with_titles_akas;
    std::string filename_with_titles_basics;
    std::string filename_with_actor_movie_link;
    bool is_full() {
        return (!person_name.empty() && 
            !person_surname.empty() &&
            !filename_with_persons.empty() &&
            !filename_with_titles_akas.empty() &&
            !filename_with_titles_basics.empty() &&
            !filename_with_actor_movie_link.empty())
            ? true : false;
    }
};

arguments_t get_arguments(int argc, char *argv[]);

void search_field(std::ifstream& file, person_t& pers, search_box field);

void str_split(std::string& str, char sep, std::vector <std::string>& str_vect);