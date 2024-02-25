#include <stdio.h>
#include <stdlib.h>

void func()
{
    int* arr = malloc(10*sizeof(int));

    arr[2] = 10;
    arr[3] = arr[2]*5;

    free(arr);
}

int main()
{
    printf("no leak process\n");

    func();

    return 0;
}