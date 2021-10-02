#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define MAX_LINE 80

int main(void)
{
    char *arg[MAX_LINE/2+1]; /*command line arguments*/
    int should_run = 1; /*flag to determine when to exit program*/
    
    while(should_run){
        printf("osh>");
        fflush(stdout);
        
        /**
        * your code!
        * After reading user input, the step are:
        * (1) fork a child process using fork()
        * (2) the child process will invoke execvp()
        */
        char com[MAX_LINE];
        pid_t pid;
        read(0, com, MAX_LINE/2+1);
        arg[0] = strtok(com," ");
        
        int count = 0;
        while(arg[count] != NULL){
            arg[++count] = strtok(NULL," ");
        }
        
        
        if(strcmp(com,"exit\n") == 0){
            return 0;
        }
        else{
            pid = fork();
            if(pid == 0){
                /*
                char* temp = NULL;
                temp = strstr(arg[0], "\n");
                *temp = '\0';
                */
                
                char z[MAX_LINE];
                strcpy(z, arg[0]);
                z[strlen(z)-1] = '\0';
                
                execvp(z, arg);
            }
            else if(pid > 0){
                wait(NULL);
            }
        }
        
    }
    return 0;
}


