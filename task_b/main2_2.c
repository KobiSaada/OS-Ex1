#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 30
char child_stack[STACK_SIZE+1]; 

void print(const char *text){//The function fork and clone processes are using
    int i;
    for(i=0;i<CYCLES;i++){
     
        usleep(3000000);
    }
}

int child1(){
    print("thread");
    return 0;
}


int main() {
// run "child" in "childStack"'s size and clone parent
    int myclone1 = clone(child1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    int myclone2 = clone(child1, child_stack+STACK_SIZE, CLONE_PARENT, 0);
    printf("clone id result = %d\n", myclone1);
    printf("clone id result = %d\n", myclone2);
    child1();
    printf("parent id %d\n", getpid());

    return 0;
}
