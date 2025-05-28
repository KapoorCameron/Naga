#include <iostream>
#include <string>
#include <windows.h> // include before shellapi.h b/c shellapi depends on types and macros defined in windows.h
#include <shellapi.h>
#include <filesystem> //c++'s standard library header that allows for platform-independent file system access.  
#include<system_error>

#include "directories.h"
#include "../utils/paths.h"

// Create a directory and (if specified) open it:
void makeDirectory(const std::string& location, const std::string& name, bool openAfter) 
{
    namespace fs = std::filesystem; // allows for "fs::path" and "fs::create_directories" instead of longform "std::filesystem::path" and "std::filesystem::create_directories"

    // to resolve [location] parameter to valid directory path:
    fs::path basePath = resolvePath(location);
    // ^^we create a variable of type std::filesystem::path called basePath to hold the resolved path leading to the [location] parameter. THIS VARIABLE SIMPLY STORES THE PATH TO THE LOCATION PARAMETER.
    if (basePath.empty())
    {
        std::cerr << "Unsupported location: " << location << "\n";
        return; 
    }

    fs::path fullPath = basePath / name; // "/" is overloaded in cases like this to concatenate. 

    // this is the part of the code that takes in the full path as an argument and creates any parent directories needed to have the full "written" path become an actual chain of directories in the computer:
    std::error_code ec; // we create a variable of type std::error_code to hold any error messages from the OS when creating a directoriy. The OS simply writes the message to our ec variable. 
    bool created = fs::create_directories(fullPath, ec);

    // check to see if full path already exists or if we were successfully able to create it if it didn't exist. We then provide feedback to the user and open if specified: 
    if (created || fs::exists(fullPath))
    {
        std::cout << "Created directory: \"" << fullPath << "\"\n";

        if (openAfter) 
        {
            SHELLEXECUTEINFOA sei = { 0 };
            sei.cbSize = sizeof(SHELLEXECUTEINFOA);
            sei.fMask = SEE_MASK_NOCLOSEPROCESS;
            sei.hwnd = NULL;
            sei.lpVerb = "open";
            sei.lpFile = fullPath.string().c_str();
            sei.nShow = SW_SHOWNORMAL;

            if (ShellExecuteExA(&sei))
            {
                // Try bringing window to foreground (optional)
                HWND hwnd = FindWindowA(NULL, name.c_str()); 
                if (hwnd)
                {
                    SetForegroundWindow(hwnd);
                    SetActiveWindow(hwnd);
                    ShowWindow(hwnd, SW_RESTORE);
                }
            }
            else
            {
                std::cerr << "Failed to open directory.\n";
            }
        }
    }

    else 
    {
        std::cerr << "Failed to create directory: " << ec.message() << "\n";
    }

}

