#ifndef COMMAND_LINE_PARSER_HPP
#define COMMAND_LINE_PARSER_HPP

#include <vector>
#include <string>

namespace std_ext {


class CommandLineParser
{
public:
    CommandLineParser(int argc, char *argv[]);
    ~CommandLineParser();

    bool isOptionSet(char short_opt);
    bool isOptionSet(char short_opt, std::string long_opt);

    bool getParameter(char short_opt, std::string long_opt, std::string& parameter);
    bool getParameter(char short_opt, std::string long_opt, int& parameter);
//    bool getParameter(char short_opt, std::string long_opt, T& parameter); template ?

private:
    std::vector<std::string> arg_vector;
    std::vector<std::string> opt_vector;
    std::string argument;

};


}  // namespace Tools

#endif // COMMAND_LINE_PARSER_HPP
