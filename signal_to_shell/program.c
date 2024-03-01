#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    printf("main program start\n");
    sleep(3);
    
    if(rand()%2 == 0) {
        printf("send signal\n");
        kill(getppid(), SIGUSR1);
        
    }
    else {
        printf("not send signal\n");
    }
    
    sleep(3);
    printf("main program end\n");

    return 0;
}