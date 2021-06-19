//
// Created by t xiao on 2021/6/19.
//
#include "apue.h"
#include <sys/wait.h>
int
main(void)
{
    pid_t pid;
    int status;
    if((pid=fork())<0){
        printf("fork error");
    } else if (pid==0) {
        sleep(2);
        printf("i am child\n");
        exit(0);
    }
    wait(&status);

    printf("i am par\n");
}

