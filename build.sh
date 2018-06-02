#/bin/bash

# this changes the permissions so that it is executable : chmod a+x build.sh 
# only have to say ./build.sh instead of bash build.sh

# what you want to run in this build so that you don't have to worry in terminal
# you may add to this list ie. decoder.cpp

g++ -Wall -std=c++11 coder.cpp -o coder.exe
g++ -Wall -std=c++11 decoder.cpp -o decoder.exe