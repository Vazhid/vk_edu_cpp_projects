#include <iostream>
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>
#include <algorithm>
#include <getopt.h>

#include "foo.hpp"

void search_field(std::ifstream& file, person_t& pers, search_box field) {
    std::string str_input;
    std::vector <std::string> vect_of_tokens;
    title_t tmp_title;
    
    while (file) {
        getline(file, str_input, '\n');
        str_split(str_input, '\t', vect_of_tokens);

        switch (field) {
        case PERSON_ID:
            if (vect_of_tokens[1] == pers.primary_name) {
                pers.id = vect_of_tokens[0];
                break;
            }
        
        case TITLE_ID:
            if (vect_of_tokens[2] == pers.id && (vect_of_tokens[3] == "actor" || vect_of_tokens[3] == "actress")){
                tmp_title.id = vect_of_tokens[0];
                pers.titile_list.push_back(tmp_title);
            }
        
        case TITLE_CHECK:
            for (size_t i = 0; i < pers.titile_list.size(); i++) {
                if (vect_of_tokens[0] == pers.titile_list[i].id) {
                    pers.titile_list[i].title_type == vect_of_tokens[1];
                    pers.titile_list[i].title_name = vect_of_tokens[3];
                }
            }

        case TITLE_NAME:
            for (size_t i = 0; i < pers.titile_list.size(); i++) {
                if (vect_of_tokens[0] == pers.titile_list[i].id && vect_of_tokens[3] == "RU") {
                    pers.titile_list[i].title_name = vect_of_tokens[2];
                } 
            }
            
        default:
            break;
        }

        vect_of_tokens.clear();
    }
}

void str_split(std::string& str, char sep, std::vector <std::string>& str_vect) {
    std::string tmp_str;
    std::stringstream str_stream(str);

    while (str_stream) {
        getline(str_stream, tmp_str, sep);
        str_vect.push_back(tmp_str);
    }   
}

arguments_t get_arguments(int argc, char *argv[]) {
    int c, option_index;
    arguments_t args;
    std::string name_flag = "name";
    std::string surname_flag = "surname";
    std::string title_akas_path_flag = "title-akas-path";
    std::string name_basics_path_flag = "name-basics-path"; 
    std::string title_basics_path_flag = "title-basics-path"; 
    std::string title_principals_path_flag = "title-principals-path";

    static struct option long_options[] {
        {"name", required_argument, 0, 0},
        {"surname", required_argument, 0, 0},
        {"title-akas-path", required_argument, 0, 0},
        {"name-basics-path", required_argument, 0, 0},
        {"title-basics-path", required_argument, 0, 0},
        {"title-principals-path", required_argument, 0, 0},
        {0, 0, 0, 0}
    }; 

    while (c = (getopt_long_only(argc, argv, "", long_options, &option_index)) != -1)
    {
        std::string argument = long_options[option_index].name;
        if(argument == name_flag) {
            args.person_name = optarg;
        }
        if(argument == surname_flag) {
            args.person_surname = optarg;
        }
        if(argument == title_akas_path_flag) {
            args.filename_with_titles_akas = optarg;
        }
        if(argument == title_basics_path_flag) {
            args.filename_with_titles_basics = optarg;
        }
        if(argument == name_basics_path_flag) {
            args.filename_with_persons = optarg;
        }
        if(argument == title_principals_path_flag) {
            args.filename_with_actor_movie_link = optarg;
        }
    }
    return args;
}