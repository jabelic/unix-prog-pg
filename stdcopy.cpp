// #include "./apue.3e/include/apue.h"
#include <unistd.h>
#include <stdio.h>

// #include "apue.h"

#define BUFFSIZE 4096

// 標準入力から読み込み標準出力に書き出し
int main(void){
    int n;
    char buf[BUFFSIZE];

    while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
        if (write(STDOUT_FILENO, buf, n) != n){
            // err_sys("write error");
            fprintf(stdout, "write error");
            _exit(1);
        }
    }
    if (n < 0){
        // err_sys("read error");
        fprintf(stdout, "read error");
        _exit(1);
    }
    _exit(0);
}