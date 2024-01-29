@echo off

if not exist build mkdir build
pushd build

set RAYLIB_INCLUDE_DIR=C:\raylib\raylib\src
set RAYLIB_LIB_DIR=C:\raylib\raylib\src
set RAYLIB_RES_FILE=C:\raylib\raylib\src\raylib.rc.data

gcc ../src/main.c -o main.exe %RAYLIB_RES_FILE% -s -O3 -I%RAYLIB_INCLUDE_DIR% -L%RAYLIB_LIB_DIR% -lraylib -lopengl32 -lgdi32 -lwinmm -std=c99 -Wall -mwindows
popd 