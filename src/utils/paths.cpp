#include <algorithm>
#include <windows.h>
#include <shlobj.h>

#include "paths.h"

// Get a known Windows special folder like Desktop or Documents. These are predefined directories that Windows OS uses to automatically store certain user and system data. They're accessed programatically via identifiers like FOLDERID_Desktop and FOLDERID_Documents. Further down in our code, in resolvePath(), if the keywords "desktop" or "documents" are found, getKnownFolderPath is called.
std::string getKnownFolderPath(REFKNOWNFOLDERID folderID) 
{
    PWSTR path = nullptr;

    if (SUCCEEDED(SHGetKnownFolderPath(folderID, 0, NULL, &path))) 
    {
        std::wstring ws(path);

        CoTaskMemFree(path); // we had to add ole32.lib to build.bat linker flags for this function's implementation

        return std::string(ws.begin(), ws.end());
    }

    return "";
}

// Main path resolution function
std::filesystem::path resolvePath(const std::string& raw_input) 
{
    std::string input = raw_input;

    // convert input to all lowercase:
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Strip quotes if present
    if (!input.empty() && input.front() == '"' && input.back() == '"') 
    {
        input = input.substr(1, input.size() - 2);
    }

    // Keyword mapping
    if (input == "desktop") 
    {
        return getKnownFolderPath(FOLDERID_Desktop);
    }

    else if (input == "documents") 
    {
        return getKnownFolderPath(FOLDERID_Documents);
    }

    else if (input == "cwd") 
    {
        return std::filesystem::current_path();
    }

    // General path resolution
    std::filesystem::path p(input);
    if (p.is_relative()) 
    {
        p = std::filesystem::current_path() / p;
    }


    return std::filesystem::weakly_canonical(p); 
}
