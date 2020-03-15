rmdir /s build 
pause
mkdir build
copy CMakeCache.txt build
cd build
cmake CMakeCache.txt
pause