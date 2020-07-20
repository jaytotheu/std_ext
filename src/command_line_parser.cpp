#include "command_line_parser.hpp"
#include <string>


namespace std_ext {

CommandLineParser::CommandLineParser(int argc, char *argv[])
{
    bool parse_options = true;
    for(int i=0; i < argc; i++) {
      argument = argv[i];
      arg_vector.push_back(argument);
      if (argument == "--"){
          parse_options = false;
      } // Ending options
      if (parse_options){
          opt_vector.push_back(argument);
      }
    }
}

CommandLineParser::~CommandLineParser()
{

}

bool CommandLineParser::isOptionSet(char short_opt){
    for(auto opt = opt_vector.begin(); opt != opt_vector.end(); ++opt){
        if ( (*opt).find("--") == 0){
            continue;
        }
        if ( (*opt).find("-") == 0){
            if ( (*opt).find(short_opt) != std::string::npos){
                return true;
            }
        }
//        std::cout << std::distance(arg_vector.begin(), arg) << ' ';
//        std::cout << *arg << std::endl;
    }
    return false;
}


bool CommandLineParser::isOptionSet(char short_opt, std::string long_opt){
    for(auto opt = opt_vector.begin(); opt != opt_vector.end(); ++opt){
        if ( (*opt).find("--") == 0){
            if ( (*opt).find(long_opt) != std::string::npos){
                return true;
            }
            continue;
        }
        if ( (*opt).find("-") == 0){
            if ( (*opt).find(short_opt) != std::string::npos){
                return true;
            }
        }
    }
    return false;
}


bool CommandLineParser::getParameter(char short_opt, std::string long_opt, std::string& parameter)
{
    bool last_loop = false;
    for(auto opt = opt_vector.begin(); opt != opt_vector.end(); ++opt){
        auto next = opt;
        ++next;
        if (next == opt_vector.end()){
            last_loop = true;
        }
        if ( (*opt).find("--") == 0){
            if ( (*opt).find(long_opt) != std::string::npos){
                parameter = (*next);
                return true;
            }
            if (last_loop){
                return false;
            } else {
                continue;
            }
        }
        if ( (*opt).find("-") == 0){
            if ( (*opt).find(short_opt) != std::string::npos){
                parameter = (*next);
                return true;
            }
        }
        if (last_loop){
            return false;
        }
    }
    return false;
}


} // namespace std_ext
