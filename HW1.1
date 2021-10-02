#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    pid = fork();//f0
    if(pid ==0){
        printf("f0 im %d my pa is %d\n",getpid(),getppid());
        pid = fork();//f1
        if(pid > 0)
            wait(NULL);
        else if(pid == 0)
            printf("f1 im %d my pa is %d\n",getpid(),getppid());
        pid = fork();//f2
        if(pid > 0)
            wait(NULL);
        else if(pid == 0)
            printf("f2 im %d my pa is %d\n",getpid(),getppid());
    }
    else if(pid >0){
        wait(NULL);
        pid = fork();//f3
        if(pid > 0)
            wait(NULL);
        else if(pid ==0)
            printf("f3 im %d my pa is %d\n",getpid(),getppid());
    }
    else{
        printf("Error!");
    }
    pid = fork();//f4
    if(pid > 0)
        wait(NULL);
    else if(pid ==0)
        printf("f4 im %d my pa is %d\n",getpid(),getppid());
    
    printf("end\n");
    return 0;
}
