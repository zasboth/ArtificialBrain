rmdir /s build 
mkdir build
copy CMakeCache.txt build
cd build
cmake CMakeCache.txt
pause