#ifndef CODINGCHALLENGES_WORDCOUNT_PARSEARGS_H_
#define CODINGCHALLENGES_WORDCOUNT_PARSEARGS_H_

#include "stdheaders.h"

struct valid_arguments
{
    bool count_bytes;
    bool count_characters;
    bool count_words;
    bool count_lines;
    std::vector<std::string> filepath;
};

struct valid_arguments parse_command_line(int argc, char *argv[]);

#endif