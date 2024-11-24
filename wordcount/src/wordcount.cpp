#include "parseargs.h"
#include "stdheaders.h"

int main(int argc, char *argv[])
{

    struct valid_arguments va{};
    if (argc > 1)
    {
        va = parse_command_line(argc, argv);
    }
    else
    {
        // std::vector<std::string> args = { "ccwc", "-cl" };
        std::vector<std::string> args = {"ccwc", "-l", "-w", "-m", "test.txt"};
        std::vector<char *> arguments;
        for (std::string &s : args)
            arguments.push_back(&s[0]);
        arguments.push_back(NULL);

        va = parse_command_line(static_cast<int>(arguments.size() - 1), arguments.data());
    }

    std::cout << "show word count? " << std::boolalpha << va.count_words << "\n";
    std::cout << "show line count? " << std::boolalpha << va.count_lines << "\n";
    std::cout << "show char count? " << std::boolalpha << va.count_characters << "\n";
    std::cout << "show bytes count? " << std::boolalpha << va.count_bytes << "\n";
    for (auto &file : va.filepath)
        std::cout << "File path: " << file << "\n";

    return EXIT_SUCCESS;
}