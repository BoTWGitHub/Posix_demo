#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main() {
    int count = 10;
    struct timespec ts;
    char buffer[100];
    char str[1024];

    ts.tv_sec = 2;
    ts.tv_nsec = 0;

    while(count--) {
        time_t now;
        struct tm *tm_info;
        time(&now);
        tm_info = localtime(&now);
        strftime(buffer, sizeof(buffer), "%a, %d %b %Y %T %z", tm_info);
        sprintf(str, "timestamp:%s\n", buffer);
        printf("%s", str);
        int res = clock_nanosleep(CLOCK_MONOTONIC, 0, &ts, NULL);
        if(res != 0) {
            printf("nano sleep error\n");
            return 1;
        }
    }

    return 0;
}
