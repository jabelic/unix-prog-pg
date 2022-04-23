// #include "../apue.3e/include/apue.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 4096

/** minimalなプロンプトの再現プログラム */

int main(void){
    char buf[MAXLINE];
    pid_t pid; // process id の型. getpid() 
    int status;
    printf("%% "); /** プロンプトを表示 */
    while(fgets(buf, MAXLINE, stdin) != NULL){
        /**
         * "ではなく,'でないとダメみたい。
         * 改行(newline)文字をnullバイトで置き換える
         */
        if(buf[strlen(buf) - 1] == '\n') buf[strlen(buf) - 1] = 0;
        // if((pid = fork()) < 0)err_sys("fork error");
        // fork system callでprocessを作成
        if((pid = fork()) < 0){
            fprintf(stderr, "fork error");
            exit(0);
        }
        else if (pid == 0){
            /** 入力されたコマンドを実行する */
            execlp(buf, buf, (char *)0);
            // err_ret("couldn't execute: %s", buf);
            fprintf(stderr,"couldn't execute: %s", buf);
            exit(127);
        }
        // if((pid = waitpid(pid, &status, 0)) < 0) err_sys("waitpid error");
        if((pid = waitpid(pid, &status, 0)) < 0){
            fprintf(stderr, "waitpid error");
            exit(0);
        }
        printf("%% ");
    }
    exit(0);
    // return 0;
}