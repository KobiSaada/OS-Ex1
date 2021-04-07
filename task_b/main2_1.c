#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print(const char *text){//The function fork and clone processes are using
    int i;
    for(i=0;i<10;i++){
    printf("hello from%s\n" ,text);
     
        usleep(1000000);
    }
}



int main() {
    pid_t app = getpid();
    int firstFork = fork();

    if(firstFork< 0) //fork failed
        exit(EXIT_FAILURE);

    if(firstFork == 0) { //his is the child process
        pid_t process1 = getpid();
        int secondFork = fork();

        if(secondFork < 0) //fork failed
            exit(EXIT_FAILURE);

        if(secondFork == 0) {
            pid_t process2 = getpid();
            printf("Process 2 %d --> \n", process2);
            print("Process 2");
            
           // sleep(3000000);
        }
        else  { 
            printf("Process 1 %d --> \n", process1);
            print("Process 1");
            
           // sleep(3000000);
           }
    }
    else{
        printf("App %d --> \n", app);
        print("app");
       }
//usleep(3000000);
    return 0;
}
