// #include "apue.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (void){
    printf("hello world from processs ID %ld\n", (long)getpid());
    // exit(0);
    return 0;
}