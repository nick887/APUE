//
// Created by t xiao on 2021/6/19.
//
#include "apue.h"
int globvar = 6;
char buf[]="a write to stdout\n";

int
main(void)
{
    int var;
    pid_t pid;

    var = 88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
        err_sys("write error");
    printf("before fork\n");

    //子进程返回0，父进程返回值为新创建子进程的pid id
    //子进程获取父进程的栈堆，数据空间副本
    if((pid=fork())<0)
        err_sys("fork error");
    else if (pid == 0){
        globvar++;
        var++;
    } else{
        sleep(2);
    }
    printf("pid = %ld , glob =%d , var = %d\n",(long)getpid(),globvar,var);
    exit(0);
}

