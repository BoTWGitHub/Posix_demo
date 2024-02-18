#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/bin/gedit", "gedit", "test.txt");

    //should never run to here
    return 0;
}