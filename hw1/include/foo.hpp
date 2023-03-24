#pragma once

#include <vector>
#include <iostream>

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

std::vector <std::string> str_split_to_vect(std::string& str, char sep);

void person_id_search_by_name(std::ifstream& file, person_t& pers);

void title_id_search_by_person_id(std::ifstream& file, person_t& pers);

void movie_check_by_title_id(std::ifstream& file, person_t& pers);

void title_search_by_title_id(std::ifstream& file, person_t& pers);

arguments_t get_arguments(int argc, char *argv[]);