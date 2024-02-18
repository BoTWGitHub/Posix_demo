#include <stdio.h>

int main(int argc, char* argv[])
{
    int i;
    printf("Hello, world!\n");
    printf("%d var\n", argc);
    for(i=0;i<argc;i++){
        printf("No.%d: %s\n", i+1, argv[i]);
    }
    return 0;
}