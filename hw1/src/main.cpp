#include <iostream>
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>
#include <algorithm>
using namespace std;

#include "foo.hpp"

string filename_with_persons;
string filename_with_actor_movie_link;
string filename_with_titles_akas;
string filename_with_titles_basics;
int count_of_filenames = 0;

int main(int argc, char *argv[]) {
    string person_name;
    person tmp;

    if (argc > 1) {
        person_name = static_cast<string>(argv[1]) + " " + static_cast<string>(argv[2]);

        for (size_t i = 3; i < argc; i++) {
            if (static_cast<string>(argv[i]) == "--title-principals-path") {
                filename_with_actor_movie_link = static_cast<string>(argv[i + 1]);
                count_of_filenames++;

            } else if (static_cast<string>(argv[i]) == "--title-akas-path") {
                filename_with_titles_akas = static_cast<string>(argv[i + 1]);
                count_of_filenames++;

            } else if (static_cast<string>(argv[i]) == "--title-basics-path") {
                filename_with_titles_basics = static_cast<string>(argv[i + 1]);
                count_of_filenames++;

            } else if (static_cast<string>(argv[i]) == "--name-basics-path") {
                filename_with_persons = static_cast<string>(argv[i + 1]);
                count_of_filenames++;
            }
        }

        if (count_of_filenames < 4) {
            cerr << "Where my arguments?" << endl;
            return 1;
        }

        tmp.primary_name = person_name;
    } else {
        cerr << "The peson's name was not transmitted!" << std::endl;
        return 1;
    }

    ifstream names{ filename_with_persons };

    if(!names) {
        cerr << filename_with_persons << " could not be opened for reading!" << std::endl;
        return 1;
    }

    ifstream links{ filename_with_actor_movie_link };
    
    if(!links) {
        cerr << filename_with_actor_movie_link << " could not be opened for reading!" << std::endl;
        return 1;
    }

    ifstream tit_basics{ filename_with_titles_basics };

    if(!tit_basics) {
        cerr << filename_with_titles_basics << " could not be opened for reading!" << std::endl;
        return 1;
    }

    ifstream tit_akas{ filename_with_titles_akas };

    if(!tit_akas) {
        cerr << filename_with_titles_akas << " could not be opened for reading!" << std::endl;
        return 1;
    }

    nconst_search_by_name_in_file(names, tmp);

    if (!tmp.nconst.empty()) {
        tconst_search_by_nconst_in_file(links, tmp);

        if (!tmp.titile_list.empty()) {
            movie_check_by_tconst_in_file(tit_basics, tmp);
            title_search_by_tconst_in_file(tit_akas, tmp);  
        } else {
            cerr << "This person has not acted in films!" << std::endl;
            return 1;
        }
    } else {
        cerr << "Name was not found in the database!\nCheck it to make sure it is correct!" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < tmp.titile_list.size(); i++) {
        if (!tmp.titile_list[i].title_name.empty() && tmp.titile_list[i].is_movie) {
            cout << tmp.titile_list[i].title_name << endl;
        }
    }

    return 0;
}