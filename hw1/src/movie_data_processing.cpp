#include "movie_data_processing.hpp"

bool title_t::is_movie() {
    return (title_type == MOVIE_COLNAME) ? true : false;
}

bool arguments_t::is_full() {
    return (!person_name.empty() && 
        !person_surname.empty() &&
        !filename_with_persons.empty() &&
        !filename_with_titles_akas.empty() &&
        !filename_with_titles_basics.empty() &&
        !filename_with_actor_movie_link.empty())
        ? true : false;
}

void search_field(std::istream& file, person_t& pers, search_box field) {
    std::string str_input;
    std::vector <std::string> vect_of_tokens;
    title_t tmp_title;
    
    while (file) {
        getline(file, str_input, '\n');
        str_split(str_input, '\t', vect_of_tokens);

        switch (field) {
        case PERSON_ID:
            if (vect_of_tokens[PRIMARY_NAME_INDEX_IN_NAMES] == pers.primary_name) {
                pers.id = vect_of_tokens[PERSON_ID_INDEX_IN_NAMES];
                break;
            }
        
        case TITLE_ID:
            if (vect_of_tokens[PERSON_ID_INDEX_IN_LINKS] == pers.id && 
            (vect_of_tokens[PERSON_WORK_INDEX] == ACTOR_COLNAME || vect_of_tokens[PERSON_WORK_INDEX] == ACTRESS_COLNAME)) {
                tmp_title.id = vect_of_tokens[TITLE_ID_INDEX_IN_LINKS];
                pers.titile_list.push_back(tmp_title);
            }
        
        case TITLE_CHECK:
            for (size_t i = 0; i < pers.titile_list.size(); i++) {
                if (vect_of_tokens[PERSON_ID_INDEX_IN_TITLES] == pers.titile_list[i].id) {
                    pers.titile_list[i].title_type == vect_of_tokens[TITLE_TYPE_INDEX_IN_TITLES];
                    pers.titile_list[i].title_name = vect_of_tokens[TITLE_NAME_INDEX_IN_TITLES];
                }
            }

        case TITLE_NAME:
            for (size_t i = 0; i < pers.titile_list.size(); i++) {
                if (vect_of_tokens[PERSON_ID_INDEX_IN_TITLES_NAMES] == pers.titile_list[i].id && 
                vect_of_tokens[LANG_COLUMN_INDEX_IN_TITLES_NAMES] == RU_COLNAME) {
                    pers.titile_list[i].title_name = vect_of_tokens[TITLE_NAME_INDEX_IN_TITLES_NAMES];
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

void get_arguments(int argc, char *argv[], arguments_t& args) {
    int c, option_index;

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
        if(argument == NAME_FLAG) {
            args.person_name = optarg;
        }
        if(argument == SURNAME_FLAG) {
            args.person_surname = optarg;
        }
        if(argument == TITLE_AKAS_PATH_FLAG) {
            args.filename_with_titles_akas = optarg;
        }
        if(argument == TITLE_BASICS_PATH_FLAG) {
            args.filename_with_titles_basics = optarg;
        }
        if(argument == NAME_BASICS_PATH_FLAG) {
            args.filename_with_persons = optarg;
        }
        if(argument == TITLE_PRINCIPALS_PATH_FLAG) {
            args.filename_with_actor_movie_link = optarg;
        }
    }
}
