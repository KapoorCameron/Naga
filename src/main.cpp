#include<fstream>
#include<iomanip> // gives us std::setw(int w) (we set width for output)
#include<iostream>
#include<sstream>
#include<string>

#include<shlobj.h> // 
#include<windows.h> // includes access to Windows API, which includes access to Windows OS for system calls 

#include"naga.h" // contains all header files (,) everytime we make new files.* we include .h into naga.h.

int main() 
{
    runCommandLoop();
    
    return 0;
} // in terminal, make sure in ..\naga\build, then ./build.bat followed by ./naga