#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main()
{
    bool parent = true;
    int count = 0;
    pid_t pid = fork();

    if(pid==0){
        parent = false;
        count++;
    }
    
    printf("Hello from %s\n", parent?"parent":"child");
    if(parent) printf("Child pid is %d\n", pid);

    printf("Count from %s is %d\n", parent?"parent":"child", count);

    return 0;
}