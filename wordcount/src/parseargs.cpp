#include "parseargs.h"
#include "application.h"

#include <argparse/argparse.hpp>

static void init_valid_arguments(struct valid_arguments *va)
{
    va->count_bytes = va->count_characters = va->count_words = va->count_lines = false;
    va->filepath = std::vector<std::string>();
}

static void add_help_argument(argparse::ArgumentParser *program)
{
    program->add_argument("-h", "--help")
        .action([=](const std::string &s) {
            (void)s;
            std::cout << "Usage: wc [OPTION]... [FILE]...\n";
            std::cout << "  or:  wc [OPTION]... --files0-from=F\n";
            std::cout << "Print newline, word, and byte counts for each FILE, and a total line if\n";
            std::cout << "more than one FILE is specified.  A word is a non-zero-length sequence of\n";
            std::cout << "printable characters delimited by white space.\n";
            std::cout << "\n";
            std::cout << "With no FILE, or when FILE is -, read standard input.\n";
            std::cout << "\n";
            std::cout << "The options below may be used to select which counts are printed, always in\n";
            std::cout << "the following order: newline, word, character, byte, maximum line length.\n";
            std::cout << "  -c, --bytes            print the byte counts\n";
            std::cout << "  -m, --chars            print the character counts\n";
            std::cout << "  -l, --lines            print the newline counts\n";
            std::cout << "      --files0-from=F    read input from the files specified by\n";
            std::cout << "                           NUL-terminated names in file F;\n";
            std::cout << "                           If F is - then read names from standard input\n";
            std::cout << "  -L, --max-line-length  print the maximum display width\n";
            std::cout << "  -w, --words            print the word counts\n";
            std::cout << "      --total=WHEN       when to print a line with total counts;\n";
            std::cout << "                           WHEN can be: auto, always, only, never\n";
            std::cout << "      --help        display this help and exit\n";
            std::cout << "      --version     output version information and exit\n";
            std::cout << "\n";

            exit(EXIT_SUCCESS);
        })
        .default_value(false)
        .help("display this help and exit")
        .implicit_value(true)
        .nargs(0);
}

static void add_optional_arguments(argparse::ArgumentParser *program, struct valid_arguments *va)
{
    program->add_argument("-c", "--bytes").help("print the byte counts").flag().store_into(va->count_bytes);
    program->add_argument("-m", "--chars").help("print the character counts").flag().store_into(va->count_characters);
    program->add_argument("-l", "--lines").help("print the newline counts").flag().store_into(va->count_lines);
    program->add_argument("-w", "--words").help("print the word counts").flag().store_into(va->count_words);
}

struct valid_arguments parse_command_line(int argc, char *argv[])
{
    struct valid_arguments va;
    init_valid_arguments(&va);

    argparse::ArgumentParser program(program_name);
    add_help_argument(&program);
    add_optional_arguments(&program, &va);

    program.add_argument("FILE").remaining();

    try
    {
        program.parse_args(argc, argv);
    }
    catch (const std::exception &err)
    {
        std::cerr << std::format("{}: {}\n", program_name, err.what());
        std::cerr << std::format("Try '{} --help' for more information.\n", program_name);
        exit(EXIT_FAILURE);
    }

    try
    {
        auto files = program.get<std::vector<std::string>>("FILE");
        for (auto &file : files)
            va.filepath.push_back(file);
    }
    catch (std::logic_error &e)
    {
        (void)e;
        va.filepath = {std::string("-")};
    }

    return va;
}