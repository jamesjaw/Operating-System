#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>



int main(){

    pid_t pid;

    

    printf("Main Process ID : %d\n",getpid());

    printf("\n");

    

    pid = fork(); //f1    creat 208

    

    if(pid > 0){

        wait(NULL); // wait for 208

        //printf("208 out\n");

        pid = fork(); //f2  creat 211

        if(pid >0){

            wait(NULL);  //wait for 211

            //printf("211 out\n");

        }

        else if(pid == 0){

            printf("Fork 2. I'm the child %d, my parent is %d.\n",getpid(),getppid());

        }

        

        pid = fork(); //f3 creat 212  213

        if(pid >0){

            wait(NULL);  //wait for 212 213

            //printf("212 213 out\n");

        }

        else if(pid == 0){

            printf("Fork 3. I'm the child %d, my parent is %d.\n",getpid(),getppid());

        }

    }

    else if(pid == 0){

        printf("Fork 1. I'm the child %d, my parent is %d.\n",getpid(),getppid());

        pid = fork(); //f4   creat 209

        if(pid >0){

            wait(NULL);      //wait fot 209

            //printf("209 out\n");

        }

        else if(pid == 0){

            printf("Fork 4. I'm the child %d, my parent is %d.\n",getpid(),getppid());

            pid = fork(); //f5   creat 210

            if(pid >0){

                wait(NULL);   //wait for 210

                //printf("210 out\n");

            }

            else if(pid == 0){

                printf("Fork 5. I'm the child %d, my parent is %d.\n",getpid(),getppid());

            }

        }

        

    }

    //printf("eee\n");

    //printf("  %d  is out\n",getpid());

    return 0;

}

