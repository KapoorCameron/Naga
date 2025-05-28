#include <iostream>
#include <iomanip>

#include"secret.h"

void extended_commands()
{
    std::cout << "_&Extended Commands Directory&_\n";
    std::cout << "-------------------------------\n";

    std::cout << std::left;

    std::cout << "  " << std::setw(35) << "music"
              << "- play shuffled music library\n";

    std::cout << "  " << std::setw(35) << "music [song name]"
              << "- play specific song\n";

    std::cout << "  " << std::setw(35) << "music aggressive"
              << "- play AGGRESSIVE playlist\n";

    std::cout << "  " << std::setw(35) << "music aggressive shuffle"
              << "- shuffle AGGRESSIVE playlist\n";

    std::cout << "  " << std::setw(35) << "music somber"
              << "- play SOMBER playlist\n";

    std::cout << "  " << std::setw(35) << "music somber shuffle"
              << "- shuffle SOMBER playlist\n";

    std::cout << "  " << std::setw(35) << "music MLLFR;"
              << "- play MLLFR; playlist\n";

    std::cout << "  " << std::setw(35) << "music MLLFR shuffle;"
              << "- shuffle MLLFR; playlist\n";

    std::cout << "  " << std::setw(35) << "music MISC;"
              << "- shuffle playlist from \"MISC;\"\n";

    std::cout << "  " << std::setw(35) << "music library"
              << "- list all songs in music library\n";

    std::cout << "  " << std::setw(35) << "view"
              << "- open/display random image from art gallery\n";

    std::cout << "  " << std::setw(35) << "view [image name]"
              << "- view specific image\n";

    std::cout << "  " << std::setw(35) << "art/art gallery/gallery"
              << "- list all photos in art gallery\n";

    std::cout << "  " << std::setw(35) << "readme/README/read me/READ ME"
              << "- open project journal/learning docs\n";

    std::cout << "  " << std::setw(35) << "read [document name]"
              << "- open/display a specific document\n";

    std::cout << "\n  Enter DEV AUTH Code for NO ACCESS Directory\n";
}
