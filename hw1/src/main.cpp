#include <iostream>
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>
#include <algorithm>
#include <getopt.h>

#include "foo.hpp"

int main(int argc, char *argv[]) {
    person_t tmp;
    arguments_t args = get_arguments(argc, argv);
    
    if (!args.is_full()) {
        std::cerr << "Invalid numbers of arguments!" << std::endl;
        return 1;
    }

    std::ifstream names(args.filename_with_persons);

    if(!names.is_open()) {
        std::cerr << args.filename_with_persons << " could not be opened for reading!" << std::endl;
        return 1;
    }

    std::ifstream links(args.filename_with_actor_movie_link);
    
    if(!links.is_open()) {
        std::cerr <<args.filename_with_actor_movie_link << " could not be opened for reading!" << std::endl;
        return 1;
    }

    std::ifstream tit_basics(args.filename_with_titles_basics);

    if(!tit_basics.is_open()) {
        std::cerr << args.filename_with_titles_basics << " could not be opened for reading!" << std::endl;
        return 1;
    }

    std::ifstream tit_akas(args.filename_with_titles_akas);

    if(!tit_akas.is_open()) {
        std::cerr << args.filename_with_titles_akas << " could not be opened for reading!" << std::endl;
        return 1;
    }

    person_id_search_by_name(names, tmp);

    if (!tmp.id.empty()) {
        title_id_search_by_person_id(links, tmp);

        if (!tmp.titile_list.empty()) {
            movie_check_by_title_id(tit_basics, tmp);
            title_search_by_title_id(tit_akas, tmp);  
        } else {
            std::cerr << "This person has not acted in films!" << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Name was not found in the database!\nCheck it to make sure it is correct!" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < tmp.titile_list.size(); i++) {
        if (!tmp.titile_list[i].title_name.empty() && tmp.titile_list[i].is_movie()) {
            std::cout << tmp.titile_list[i].title_name << std::endl;
        }
    }

    return 0;
}
