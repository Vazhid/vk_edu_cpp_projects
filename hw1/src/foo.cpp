#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "foo.hpp"

vector <string> str_split_to_vect(string& str, char sep) {
    string tmp_str;
    vector <string> str_vect;
    stringstream str_stream(str);
    string token;

    while (str_stream) {
        getline(str_stream, tmp_str, sep);
        str_vect.push_back(tmp_str);
    }
    
    return str_vect;
}

void nconst_search_by_name_in_file(ifstream& file, person& pers) {
    string str_input;
    vector <string> vect_of_tokens;
    
    while (file) {
        getline(file, str_input, '\n');
        vect_of_tokens = str_split_to_vect(str_input, '\t');
        
        if (vect_of_tokens[1] == pers.primary_name){
            pers.nconst = vect_of_tokens[0];
            break;
        }
    }
}

void tconst_search_by_nconst_in_file(ifstream& file, person& pers) {
    string str_input;
    vector <string> vect_of_tokens;
    title tmp_title;

    while (file) {
        getline(file, str_input, '\n');
        vect_of_tokens = str_split_to_vect(str_input, '\t');

        if (vect_of_tokens[2] == pers.nconst && (vect_of_tokens[3] == "actor" || vect_of_tokens[3] == "actress")){
            tmp_title.tconst = vect_of_tokens[0];
            pers.titile_list.push_back(tmp_title);
        }
    }
}

void movie_check_by_tconst_in_file(ifstream& file, person& pers) {
    string str_input;
    vector <string> vect_of_tokens;

    while (file) {
        getline(file, str_input, '\n');
        vect_of_tokens = str_split_to_vect(str_input, '\t');

        for (size_t i = 0; i < pers.titile_list.size(); i++) {
            if (vect_of_tokens[0] == pers.titile_list[i].tconst && vect_of_tokens[1] != "movie") {
                pers.titile_list[i].is_movie == false;
            } else if (vect_of_tokens[0] == pers.titile_list[i].tconst && vect_of_tokens[1] == "movie") {
                pers.titile_list[i].is_movie == true;
                pers.titile_list[i].title_name = vect_of_tokens[3];
            }
        }
        

    }

}

void title_search_by_tconst_in_file(ifstream& file, person& pers) {
    string str_input;
    vector <string> vect_of_tokens;

    while (file) {
        getline(file, str_input, '\n');
        vect_of_tokens = str_split_to_vect(str_input, '\t');
        
        for (size_t i = 0; i < pers.titile_list.size(); i++) {
            if (vect_of_tokens[0] == pers.titile_list[i].tconst && vect_of_tokens[3] == "RU") {
                pers.titile_list[i].title_name = vect_of_tokens[2];
            } 
        }
        
    }
}