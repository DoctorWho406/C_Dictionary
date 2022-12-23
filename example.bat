@echo off

set BAT_BASE_PATH=%~p0

IF EXIST "%BAT_BASE_PATH%examples\bin" (
    RD /S /Q "%BAT_BASE_PATH%examples\bin"
)

MD "%BAT_BASE_PATH%examples\bin"

COPY "%BAT_BASE_PATH%library\linkedlist.dll" "%BAT_BASE_PATH%examples\bin\linkedlist.dll"
COPY "%BAT_BASE_PATH%library\hash.dll" "%BAT_BASE_PATH%examples\bin\hash.dll"
COPY "%BAT_BASE_PATH%library\set.dll" "%BAT_BASE_PATH%examples\bin\set.dll"

clang -o "%BAT_BASE_PATH%examples\bin\Example.exe" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%examples\include" "%BAT_BASE_PATH%examples\src\main.c" "%BAT_BASE_PATH%examples\src\IntItem.c" "%BAT_BASE_PATH%src\Dictionary.c" -l hash -l linkedlist -l set -L "%BAT_BASE_PATH%library" 

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.exp" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.exp"
)

IF EXIST "%BAT_BASE_PATH%examples\bin\Example.lib" (
    DEL /Q "%BAT_BASE_PATH%examples\bin\Example.lib"
)