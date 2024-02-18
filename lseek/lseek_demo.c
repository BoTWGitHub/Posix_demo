#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt", O_RDONLY);
    if(fd == -1){
        printf("open test.txt failed\n");
        return 1;
    }

    if(lseek(fd, -5, SEEK_END) == -1){
        printf("lseek failed\n");
        return 1;
    }

    char buf[1024];
    int n = read(fd, buf, sizeof(buf));
    if(n == -1){
        printf("read failed\n");
        return 1;
    }

    buf[n] = '\0';
    printf("%s\n", buf);

    close(fd);
    return 0;
}