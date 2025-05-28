#include<iomanip>
#include<iostream>

#include"help.h"

void help() 
{
    std::cout << "\nCommands:\n\n";

    std::cout << "  " << std::left << std::setw(40) << "quit" << " - quit Naga\n";

    std::cout << "  " << std::left << std::setw(40) << "md [Location] [\"Name\"]"
              << " - Create named directory in specified location\n";
              

    std::cout << "  " << std::left << std::setw(40) << "mf [Location] [\"Name\"]"
              << " - Create named file in specified location\n";

    std::cout << "  " << std::left << std::setw(40) << "go [Application]"
              << " - Launch specified application\n";

    std::cout << "  " << std::left << std::setw(40) << "no [Application]"
              << " - Quit specified application\n";

    std::cout << "  " << std::left << std::setw(40) << "play"
              << " - Shuffle and play playlist\n";

    std::cout << "  " << std::left << std::setw(40) << "stop"
              << " - Stop currently playing audio media\n";

    std::cout << "  " << std::left << std::setw(40) << "fx"
              << " - Toggle sound effects on/off\n";

    std::cout << "\n  Enter AUTH Code to open Extended Command Directory\n"; 

}