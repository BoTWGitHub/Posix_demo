#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/queue.h>
#include <unistd.h>

#define NUM_OF_NODE 10

struct thread_data {
    int id;
    int sleep_time_second;
};

struct thread_node {
    pthread_t thread;
    LIST_ENTRY(thread_node) node;
};

LIST_HEAD(listhead, thread_node) head;

void* sleep_func(void* thread_param)
{
    struct thread_data *data = (struct thread_data *)thread_param;
    printf("thread[%d] sleep for %ds\n", data->id, data->sleep_time_second);
    sleep(data->sleep_time_second);
    printf("thread[%d] finished\n", data->id);
    return thread_param;
}

int main()
{
    srand(time(NULL));

    struct listhead list_head = LIST_HEAD_INITIALIZER(head);
    LIST_INIT(&list_head);

    for(int i=0;i<NUM_OF_NODE;i++) {
        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->id = i;
        data->sleep_time_second = (rand()%9) + 2;
        struct thread_node* t = malloc(sizeof(struct thread_node));
        int rc = pthread_create(&t->thread, NULL, sleep_func, data);
        if(rc != 0) {
            printf("create pthread error\n");
            break;
        }
        LIST_INSERT_HEAD(&list_head, t, node);
    }

    struct thread_node *cur;
    struct thread_node *next;
    for(cur=LIST_FIRST(&list_head);cur!=NULL;cur=next) {
        next = LIST_NEXT(cur, node);
        pthread_join(cur->thread, NULL);
        free(cur);
    }

    printf("main thread finished\n");
    return 0;
}