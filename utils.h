#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);
void erase_all_sub_str(std::string & mainStr, const std::string & toErase);

unsigned int get_uint_between_two_str(const std::string &s,
        const std::string &start_delim,
        const std::string &stop_delim);

void add_str_x_times(std::string& main_str, std::string& str_to_add, unsigned int& x);
std::string get_file(std::string& file_path);
void write_file(std::string& file_path, std::string& content);

#endif // UTILS_H_INCLUDED
