#include "apue.h"

#define BUFFSIZE 4096

// 標準入力から読み込み標準出力に書き出し
int main(void){
    int n;
    char buf[BUFFSIZE];

    while((n=read(STDIN_FILENO, buf, BUFFSIZE)) > 0){
        if (write(STDOUT_FILENO, buf, n) != n){
            err_sys("write error");
        }
    }
    if (n < 0){
        err_sys("read error");
    }
    exit(0);
}