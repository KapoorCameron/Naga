#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <shellapi.h>
#include <filesystem>

#include "files.h"
#include "../utils/paths.h"

// Create a file in a folder and open it
void makeFile(const std::string& location, const std::string& name, bool openAfter) 
{
    std::filesystem::path basePath = resolvePath(location);
    if (basePath.empty()) 
    {
        std::cerr << "Unknown location.\n";
        return;
    }

    std::filesystem::path fullPath = basePath / name;

    std::ofstream file(fullPath);
    if (!file)
    {
        std::cerr << "Failed to create file: " << fullPath << "\n";
        return;
    }

    std::cout << "Created file: " << fullPath << "\n";

    if (openAfter) 
    {
        SHELLEXECUTEINFOA sei = { 0 };
        sei.cbSize = sizeof(SHELLEXECUTEINFOA);
        sei.fMask = SEE_MASK_NOCLOSEPROCESS;
        sei.hwnd = NULL;
        sei.lpVerb = "open";
        sei.lpFile = fullPath.string().c_str();  // Convert path to const char*
        sei.nShow = SW_SHOWNORMAL;

        if (!ShellExecuteExA(&sei))
        {
            std::cerr << "Failed to open file: " << fullPath << "\n";
        }
    }
}