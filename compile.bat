@echo off

cd lib
call compile.bat
cd ..

cd

cd test
call compile.bat
cd ..
