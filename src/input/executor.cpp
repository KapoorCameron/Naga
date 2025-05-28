#include<iostream>

#include"../commands/all_commands.h"
#include"../input/executor.h"

void executeCommand(const Command& cmd)
{
    if (cmd._is_valid == false)
    {
        std::cerr << "Invalid command\n";
        return; // exit/skip the rest of execute_command
    }

    // cmd._name represents main command ("help," "md," "mf," "go," etc.,) while _args string vector holds argument values (path/location, file /or directory names, tiling, etc)

// quit
    else if (cmd._name == "quit" || cmd._name == "cuidate")
    {
        std::cout << "Quiting program...\n\n";
        exit(0);
    }

// help
    else if (cmd._name == "help")
    {
        help();
    }

// parseltongue
    else if (cmd._name == "Parseltongue" || cmd._name == "parseltongue")
        {
            extended_commands();
        }

// makeing directories
    else if (cmd._name == "md" || cmd._name == "mdo")
    {
        if (cmd._args.size() != 2) // if "md" but invalid num of arguments 
        {
            std::cerr << "to make a directory: md <location> \"Directory Name\"\n";
            return;
        }

        std::string location = cmd._args[0];
        
        std::string directory_name = cmd._args[1];

        bool open = (cmd._name == "mdo"); // open is true when cmd._name is "mdo", false if just "md":

        makeDirectory(location, directory_name, open);

    }

// making files
    else if(cmd._name == "mf" || cmd._name == "mfo")
    {
        if (cmd._args.size() != 2) // if correct "md" but wrong arguments:
        {
            std::cerr << "to make a file: mf <location> \"File Name\"\n";
            return;
        }

        std::string location = cmd._args[0];
        std::string file_name = cmd._args[1];
        bool open = (cmd._name == "mfo");

        makeFile(location, file_name, open);
    }

    // invalid
    else
    {
        std::cerr << "Invalid command. Type \"help\" for command list.\n";
    }

}