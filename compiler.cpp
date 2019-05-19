#include <string>
#include "utils.h"

std::string compile_vf_to_bf( std::string& vf_src )
{
    std::string add = "+"; // Will find better solution to this horror later
    std::string sub = "-";
    std::string nxt = ">";
    std::string bfr = "<";
    std::string swh = "[";
    std::string ewh = "]";
    std::string out = ".";
    std::string inp = ",";

    std::string delimiter = ";";
    std::string compiled_bf;
    size_t pos = 0;
    std::string token;
    unsigned int times;

    while ((pos = vf_src.find(delimiter)) != std::string::npos) {
        token = trim(vf_src.substr(0, pos));
        times = get_uint_between_two_str(token, "(", ")");
        vf_src.erase(0, pos + delimiter.length());

        if      (token.rfind("add", 0) == 0) add_str_x_times(compiled_bf, add, times);
        else if (token.rfind("sub", 0) == 0) add_str_x_times(compiled_bf, sub, times);
        else if (token.rfind("nxt", 0) == 0) add_str_x_times(compiled_bf, nxt, times);
        else if (token.rfind("bfr", 0) == 0) add_str_x_times(compiled_bf, bfr, times);
        else if (token.rfind("swh", 0) == 0) add_str_x_times(compiled_bf, swh, times);
        else if (token.rfind("ewh", 0) == 0) add_str_x_times(compiled_bf, ewh, times);
        else if (token.rfind("out", 0) == 0) add_str_x_times(compiled_bf, out, times);
        else if (token.rfind("inp", 0) == 0) add_str_x_times(compiled_bf, inp, times);
    }

    return compiled_bf;
}
