#include<iostream>
#include<sstream>
#include<string>

#include <windows.h>
#include <shlobj.h>

#include"command_loop.h"
#include"../utils/paths.h"
#include"../utils/string_utils.h"

#include"../input/command.h"
#include"../input/executor.h"
#include"../input/parser.h"

void runCommandLoop() 
{
    std::string cwd = resolvePath("cwd").string();

    std::string input;

    std::cout << "\nW&_Naga ver 0.0.1 [4/16/25]\n";
    std::cout << "Enter \"help\" for info/list of commands\n";

    while (true) 
    {
        std::cout << "\n" << cwd << "| W&_>> ";
        std::getline(std::cin, input);

        // Trim whitespace in front and back
        trim(input); // from ...src/utils/string_utils 

        // call parse_command to create Command struct instance
        Command cmd = parseInput(input);

        // call execute_command on cmd to run through if chain and execute accordingly
        executeCommand(cmd);
    }
}