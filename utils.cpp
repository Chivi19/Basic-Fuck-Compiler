#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <exception>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s) {
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}

void eraseAllSubStr(std::string & mainStr, const std::string & toErase) {
	size_t pos = std::string::npos;

	// Search for the substring in string in a loop until nothing is found
	while ((pos  = mainStr.find(toErase) )!= std::string::npos)
	{
		// If found then erase it from string
		mainStr.erase(pos, toErase.length());
	}
}

unsigned int get_uint_between_two_str(const std::string &s,
        const std::string &start_delim,
        const std::string &stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.find(stop_delim);
    std::string delimited_string = s.substr(end_pos_of_first_delim,
            last_delim_pos - end_pos_of_first_delim);

    return std::stoul(delimited_string, nullptr, 0);
}

void add_str_x_times(std::string& main_str, std::string& str_to_add, unsigned int& x)
{
    for( unsigned int i = 0; i < x; i += 1 ) {
      main_str += str_to_add;
   }
}

std::string get_file(std::string& file_path)
{
    std::string file;

    try {
        std::ifstream inf(file_path);

        if(!inf.is_open()) {
            throw 1;
        }

        while(inf) {
            std::string data;
            inf >> data;
            file += data;
        }
    }
    catch(...) {
        std::cerr << "There was an error while trying to open \"" << file_path << "\"." << std::endl;
        exit(1);
    }

    return file;
}

void write_file(std::string& file_path, std::string& content)
{
    try {
        std::ofstream outf(file_path);

        if(!outf) {
            throw 1;
        }

        outf << content;
    }
    catch(...) {
        std::cerr << "There was an error while trying to write \"" << file_path << "\"." << std::endl;
        exit(1);
    }
}
