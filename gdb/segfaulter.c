#include <stdio.h>

void segfaulter()
{
    int* p = 0;
    *p = 10; //segmentation fault
}

int main()
{
    printf("segmentation fault trigger\n");
    segfaulter();

    return 0;
}