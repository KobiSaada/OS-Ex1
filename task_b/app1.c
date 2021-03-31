#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
        }
        else   
            printf("Process 1 %d --> \n", process1);
    }
    else
        printf("App %d --> \n", app);

    sleep(10); 
    return 0;
}
