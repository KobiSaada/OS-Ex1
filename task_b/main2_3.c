
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <syslog.h>


int main() {
    pid_t app = fork();

    if(app < 0) //fork failed
        exit(EXIT_FAILURE);

    if(app == 0) { 

        /* Change the current working directory */
        chdir("/");
        
        /* move the child to new session */
        setsid();

        printf("start daemon");


        /* Close it's input-output channels */
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        //open log

        openlog("myDaemon", LOG_PID, LOG_DAEMON);
        syslog(LOG_NOTICE, "daemon started");
        usleep(3000000);
        syslog(LOG_NOTICE, "daemon doing some work");
        usleep(3000000);
        syslog(LOG_NOTICE, "daemon finished");



    }
    else{
        printf("daemon pid %d\n", app);
    }
usleep(5);
    return 0;
}
