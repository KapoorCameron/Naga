@echo off
setlocal EnableDelayedExpansion

:: Build all source files into one command:

::// We make a variable called FILES:
set FILES= 
::// We fill FILES with all *.cpp file paths:
for /R ..\src %%f in (*.cpp) do ( 
    set FILES=!FILES! "%%f"
)

cl /std:c++17 /EHsc /Fo:junk_drawer\ /Fe:naga.exe !FILES! /I../include /link shell32.lib shlwapi.lib user32.lib ole32.lib