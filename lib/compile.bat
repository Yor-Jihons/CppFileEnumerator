@echo off
md bin > nul 2>&1
make
copy .\src\*.h .\bin\*
