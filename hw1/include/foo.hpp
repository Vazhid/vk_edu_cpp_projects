#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <getopt.h>

#define MOVIE_COLNAME "movie"
#define ACTOR_COLNAME "actor"
#define ACTRESS_COLNAME "actress"
#define RU_COLNAME "actress"

#define PRIMARY_NAME_INDEX_IN_NAMES 1
#define PERSON_ID_INDEX_IN_NAMES 0

#define PERSON_ID_INDEX_IN_LINKS 2
#define TITLE_ID_INDEX_IN_LINKS 0
#define PERSON_WORK_INDEX 3

#define PERSON_ID_INDEX_IN_TITLES 0
#define TITLE_TYPE_INDEX_IN_TITLES 1
#define TITLE_NAME_INDEX_IN_TITLES 3

#define PERSON_ID_INDEX_IN_TITLES_NAMES 0
#define LANG_COLUMN_INDEX_IN_TITLES_NAMES 3
#define TITLE_NAME_INDEX_IN_TITLES_NAMES 2

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