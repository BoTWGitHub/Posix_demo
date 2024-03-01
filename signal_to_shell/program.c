#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("main program start\n");
    sleep(3);
    
    printf("send signal\n");
    kill(getppid(), SIGUSR1);

    sleep(5);
    printf("main program end\n");

    return 0;
}