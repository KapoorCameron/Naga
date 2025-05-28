#include<iomanip>
#include<sstream>

#include"command.h"
#include"parser.h"
#include"../utils/string_utils.h"

// we pass in a const (raw_input) to ensure it's not accidentally modified
Command parseInput(const std::string& raw_input)
{
    Command cmd; // make Command struct instance

    std::string input = raw_input; // because we can't modify a const (raw_input), we assign its value to a new variable that we can modify

    trim(input);

    // b/c no struct constructor (lol,) we update struct's _name member to be user input (user command)via iss insertion:
    std::istringstream iss(input);
    iss >> cmd._name;

    // take each normal and quoted argument OUT OF iss one at a time and insert each argument into a string variable to then be pushed_back as an individual string into our struct cmd string vector _args: 
    std::string arg;

    while (iss >> std::quoted(arg) || iss >> arg) //WHILE there are strings (quoted or unquoted) in iss
    {
        cmd._args.push_back(arg);
    }

    // cmd._is_valid = !cmd._name.empty();

    if (cmd._name.empty() == true) // if user just hits enter with no command
    {
        cmd._is_valid = false;
    }

    else
    {
        cmd._is_valid = true;
    }

    return cmd;

}