@echo off

set BAT_BASE_PATH=%~p0

if exist "%BAT_BASE_PATH%dictionary" (
    RD /S /Q "%BAT_BASE_PATH%dictionary"
)

MD "%BAT_BASE_PATH%dictionary\lib"

clang -shared -o "%BAT_BASE_PATH%dictionary\lib\dictionary.dll" -I "%BAT_BASE_PATH%include" -I "%BAT_BASE_PATH%library\set\include" -L "%BAT_BASE_PATH%library\set\lib" -l set "%BAT_BASE_PATH%src\Dictionary.c"


IF %ERRORLEVEL% EQU 0 (
    MD "%BAT_BASE_PATH%dictionary\include"
    
    COPY /Y "%BAT_BASE_PATH%include\*.h" "%BAT_BASE_PATH%dictionary\include"

    COPY /Y "%BAT_BASE_PATH%library\set\include\*.h" "%BAT_BASE_PATH%dictionary\include"
)
