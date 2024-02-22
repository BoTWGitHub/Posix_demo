#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

bool caught_sigint = false;
bool caught_sigterm = false;

static void signal_handler(int signal_number)
{
    if(signal_number == SIGINT) {
        caught_sigint = true;
    }
    else if(signal_number == SIGTERM) {
        caught_sigterm = true;
    }
}

int main()
{
    struct sigaction new_action;
    bool success = true;
    memset(&new_action, 0, sizeof(struct sigaction));
    new_action.sa_handler = signal_handler;

    if(sigaction(SIGINT, &new_action, NULL) != 0) {
        printf("Error registering for SIGINT");
        success = false;
    }
    if(sigaction(SIGTERM, &new_action, NULL) != 0) {
        printf("Error registering for SIGTERM");
        success = false;
    }

    if(success) {
        printf("waiting for a signal\n");
        pause();
        if(caught_sigint) {
            printf("===> Caught SIGINT <===\n");
        }
        if(caught_sigterm) {
            printf("===> Caught SIGTERM <===\n");
        }
    }

    return 0;
}