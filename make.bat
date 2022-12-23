@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%library\dictionary.dll" (
    DEL /Q "%BAT_BASE_PATH%library\dictionary.dll"
)

if exist "%BAT_BASE_PATH%library\dictionary.exp" (
    DEL /Q "%BAT_BASE_PATH%library\dictionary.exp"
)

if exist "%BAT_BASE_PATH%library\dictionary.lib" (
    DEL /Q "%BAT_BASE_PATH%library\dictionary.lib"
)

clang -shared -o "%BAT_BASE_PATH%library\dictionary.dll" -I "%BAT_BASE_PATH%include" "%BAT_BASE_PATH%src\Dictionary.c" -l set -l hash -l linkedlist -L "%BAT_BASE_PATH%library"