//
// Created by t xiao on 2021/6/19.
//

#include "apue.h"
int globvar = 6;

int
main(void)
{
    int var;
    pid_t pid;
    var = 88;
    printf("before vfork\n");
    printf("pid =%ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
    //vfork保证子进程先执行
    //vfork子进程与父进程共享地址空间，即数据共享
    if((pid=vfork())<0){
        err_sys("vfork error");
    } else if (pid==0){
        globvar++;
        var++;
        _exit(0);
    }
    printf("pid =%ld,glob = %d,var = %d\n",(long)getpid(),globvar,var);
    exit(0);
}

