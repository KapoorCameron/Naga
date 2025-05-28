#pragma once

#include<string>
#include<vector>

struct Command
{
    std::string _name; 
    // main command ("md," "mf," "go," etc.)

    std::vector<std::string> _args; 
    // auxiliaries like PATH/location, tiling ("1/8"), directory name, etc.

    bool _is_valid = true; 
    // defaults to true 
};