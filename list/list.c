#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>

#define DATA_LEN 10

struct test_data
{
    int val;
    LIST_ENTRY(test_data) node;
};

LIST_HEAD(listhead, test_data) head;

int main()
{
    struct listhead h = LIST_HEAD_INITIALIZER(head);
    LIST_INIT(&h);

    for(int i=0;i<DATA_LEN;i++) {
        struct test_data *data = malloc(sizeof(struct test_data));
        data->val = i;
        LIST_INSERT_HEAD(&h, data, node);
    }

    struct test_data *p;
    LIST_FOREACH(p, &h, node) {
        printf("%d\n", p->val);
    }

    struct test_data *tmp;
    for(p=LIST_FIRST(&h);p!=NULL;p=tmp) {
        tmp = LIST_NEXT(p, node);
        LIST_REMOVE(p, node);
        free(p);
    }

    return 0;
}