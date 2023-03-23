#pragma once

#include <vector>
#include <iostream>
using namespace std;

struct title {
    string title_name;
    bool is_movie;
    string tconst;
};

struct person {
    string primary_name;
    string nconst;
    vector <title> titile_list;
};

vector <string> str_split_to_vect(string& str, char sep);

void nconst_search_by_name_in_file(ifstream& file, person& pers);

void tconst_search_by_nconst_in_file(ifstream& file, person& pers);

void movie_check_by_tconst_in_file(ifstream& file, person& pers);

void title_search_by_tconst_in_file(ifstream& file, person& pers);