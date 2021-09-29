#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_LINE 80

int main(void)
{
    char *arg[MAX_LINE/2+1]; /*command line arguments*/
    int should_run = 1; /*flag to determine when to exit program*/
    
    char comm[MAX_LINE];
    pid_t pid;
    while(should_run){
        printf("osh>");
        fflush(stdout);
        
        /**
        * your code!
        * After reading user input, the step are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        */
        
        read(0, comm, MAX_LINE);
        //printf("%s",arg);
        //if((char)arg[1] == 'e') return 0;
        //printf("%c",(char)arg[1]);
        
        if(comm[0] == 'c' && comm[1] == 'a' && comm[2] == 't'){
            pid = fork();
            if(pid == 0){
                arg[0] = "cat";
                arg[1] = "hi.txt";
                arg[2] = NULL;
                if(execvp("cat", arg)){
                    printf("file not found\n");
                }
            }
            else if(pid > 0){
                wait(NULL);
            }
        }
        else if(comm[0] == 'l' && comm[1] == 's'){
            pid = fork();
            if(pid == 0){
                arg[0] = "ls";
                arg[1] = NULL;
                execvp("ls", arg);
            }
            else if(pid > 0){
                wait(NULL);
            }
        }
        else if(comm[0] == 'd' && comm[1] == 'a' && comm[2] == 't' && comm[3] == 'e'){
            printf("date\n");
            pid = fork();
            if(pid == 0){
                arg[0] = "date";
                arg[1] = NULL;
                execvp("date", arg);
            }
            else if(pid > 0){
                wait(NULL);
            }
        }
        else if(comm[0] == 'p' && comm[1] == 's' && comm[2] == ' ' &&  comm[3] == '-' && comm[4] == 'f'){
            pid = fork();
            if(pid == 0){
                arg[0] = "ps";
                arg[1] = "-f";
                arg[2] = NULL;
                execvp("ps", arg);
            }
            else if(pid > 0){
                wait(NULL);
            }
        }
        else if(comm[0] == 'e' && comm[1] == 'x' && comm[2] == 'i' && comm[3] == 't'){
            break;
        }
        else{
            printf("command not supported\n");
        }
        
    }

    return 0;
}
