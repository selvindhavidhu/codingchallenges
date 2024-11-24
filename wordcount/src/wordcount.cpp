#include "wordcount.h"

#include <argparse/argparse.hpp>

int main(int argc, char *argv[])
{
    std::cout << "Hello, world\n";
    /*
    struct valid_arguments va {};
    if (argc > 1) {
        va = parse_command_line(argc, argv);
    }
    else {
        std::vector<std::string> args = { "ccwc", "-l", "-w", "-m", "test.txt" };
        std::vector<char*> arguments;
        for (std::string& s : args) arguments.push_back(&s[0]);
        arguments.push_back(NULL);

        va = parse_command_line(arguments.size() - 1, arguments.data());
    }

    std::cout << "show word count? " << std::boolalpha << va.count_words << "\n";
    std::cout << "show line count? " << std::boolalpha << va.count_lines << "\n";
    std::cout << "show char count? " << std::boolalpha << va.count_characters << "\n";
    std::cout << "show bytes count? " << std::boolalpha << va.count_bytes << "\n";
    std::cout << "File path: " << va.filepath << "\n";

    std::string file_contents{};
    if (va.filepath.empty() || (va.filepath.compare("-") == 0)) {
        file_contents = read_from_stdin();
    }
    else {
        file_contents = get_file_contents(va.filepath);
    }

    std::cout << "file size: " << file_contents.length() << "\n";*/

    return 0;
}