#include <iostream>
#include <string>
#include "utils.h"
#include "compiler.h"
#include "interpreter.h"

void build(std::string path, std::string compiled_path, int argc)
{
    if( argc < 4 ) {
        std::cout << "You're missing some arguments! the help message down below will help you!" << std::endl;
        exit(1);
    }

    std::cout << "Building...\n";
    std::string source_baf = get_file(path);
    std::string compiled_brf = compile_vf_to_bf(source_baf);

    write_file(compiled_path, compiled_brf);
}

void run(std::string path, int argc)
{
    if( argc < 3 ) {
        std::cout << "You're missing some arguments! the help message down below will help you!" << std::endl;
        exit(1);
    }

    std::cout << "Building...\n";
    std::string source_baf = get_file(path);
    std::string compiled_brf = compile_vf_to_bf(source_baf);

    std::cout << "Running...\n";
    interpret_code(compiled_brf);
}

void help(std::string program_name)
{
    std::cout << "===========================================\n";
    std::cout << "= Basic Fuck C++ compiler and interpreter =\n";
    std::cout << "=         by Yanderella with <3           =\n";
    std::cout << "===========================================\n\n";
    std::cout << program_name << " build <source_path> <compiled_file_path>\n";
    std::cout << "  Builds the file into valid brainfuck code\n";
    std::cout << program_name << " run <source_path>\n";
    std::cout << "  It runs basic fuck code with an interpreter (compiling to brainfuck beforehand)\n\n";
    std::cout << "============ BasicFuck Guide ==============\n";
    std::cout << "BasicFuck is a more readable version of brainfuck, for following this guide ";
    std::cout << "a basic knowledge of brainfuck is needed.\n";
    std::cout << "BasicFuck code is made by tokens, each of them ends with a semicolon, ";
    std::cout << "every token is translated into one or more symbols, let's see ";
    std::cout << "an example token: \n add(2); \n";
    std::cout << "This token has a label (add) and a number of times the symbol must be repeated (2). ";
    std::cout << "Every label translates into its corresponding symbol, and the times it gets added it's equal to the number inbetween the brackets.\n";
    std::cout << "add(2) for example becomes '++'. Remember that BasicFuck is (for now) case sensitive!\n\n";
    std::cout << "============ Label Translation ============\n";
    std::cout << "add = +\nsub = -\nnxt = >\nbfr = <\nswh = [\newh = ]\nout = .\ninp = ,\n";

}

int main(int argc, char *argv[])
{

    if     ( trim( argv[1] ) == "build" ) build(argv[2], argv[3], argc);
    else if( trim( argv[1] ) == "run" )   run(argv[2], argc);
    else if( trim( argv[1] ) == "help" )  help(argv[0]);
    else {
        std::cout << "That command doesn't exist, here's the help message...\n";
        help(argv[0]);
    }

    return 0;
}
