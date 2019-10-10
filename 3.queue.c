/*************************************************************************
	> File Name: 3.queue.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月10日 星期四 10时54分32秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Queue {
    int *data;
    int head, tail;
    int length;
    int cnt;
}Queue;


Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) *n);
    q->head=q->tail = 0;
    q->length = n;
    q->cnt = 0;
    return q;
}

int empty(Queue *q) {
    return q->cnt == 0;
}

int front(Queue *q) {
    return q->data[q->head];
}

int push(Queue *q, int val) {
    if (q== NULL) return 0;
    if (q->cnt == q->length) return 0;
    q->data[q->tail ++] = val;
    if (q->tail == q->length) q->tail -= q->length;
    q->cnt++;
    return 1;
}

int pop(Queue *q) {
    if (q== NULL) return 0;
    if (empty(q)) return 0;
    q->head++;	
    if (q->head >= q->length) q->head -= q->length;
    q->cnt -= 1;
    return 1;
}


void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return;
}

void output(Queue *q) {
    printf("queue = [");
    for (int i = 0; i < q->cnt; i++) {
        int ind = (q->head + i) % q->length;
        printf(" %d ",q->data[ind]);
    }
    printf("]\n");
    return;
}

int main() {
    #define MAXOP 20
    srand(time(0));
    Queue *q = init(20);
    for (int i=0; i < MAXOP ;i++) {
        int val = rand() % 100;
        int op = rand() % 2;
        switch (op) {
            case 0:{
                printf("push %d to queue = %d\n", val, push(q, val));
            }break;
            case 1:{
                
                printf("pop %d to queue = %d\n", front(q), pop(q));
            }break;
        }
        output(q);
    }
    
    printf("head=%d, tail = %d, cnt = %d\n", q->head,q->tail, q->cnt);
    for (int i = 0; i < 20; i++) {
        int val = rand()%100;
        printf("push %d to queue = %d\n", val, push(q,val));
    }
    output(q);
    return 0;
}

