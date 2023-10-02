// Adapted from this video: https://www.youtube.com/watch?v=Dq8l1_-QgAc

#include <cstdio>

void scanUserInput(int& toPopulate) {
    // Bug here because we should pass
    // &toPopulate, instead of "toPopulate"
    std::scanf("%d", toPopulate);
}

int main() {
    int d = 2;
    std::printf("Welcome to a program with a bug\n");
    std::printf("Type in an integer: \n");
    scanUserInput(d);
    std::printf("You gave me: %d", d);
    return 0;
}

/* 

Useful stuff: 
1. Where to find core files in Ubuntu LTS 22.04
https://askubuntu.com/questions/1349047/where-do-i-find-core-dump-files-and-how-do-i-view-and-analyze-the-backtrace-st


*/
