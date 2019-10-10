/*************************************************************************
	> File Name: 2.linklist.c
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月10日 星期四 10时29分25秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

typedef struct Linklist{
    ListNode head;
    int length;
} Linklist;

ListNode *init_listnode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

Linklist *init_list() {
    Linklist *l = (Linklist *)malloc(sizeof(Linklist));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_listnode(ListNode *node) {
    if (node == NULL) return;
    free(node);
    return ;
}

void clear_linklist(Linklist *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while(p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(Linklist *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = init_listnode(val);
    while(ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(Linklist *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while(ind--) {
        p = p->next;
    }
    q = p->next->next;
    clear_listnode(p->next);
    p->next = q;
    l->length -= 1;
    return 1;
}

void output(Linklist *l) {
    printf("Linklist(%d) :", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL\n");
    return ;
}

#define MAX_OP 23



int main() {
    srand(time(0));
    Linklist *l = init_list();
    int op, val, ind;
    for (int i = 0; i < MAX_OP; i++) {
        op = rand()%3;
        val = rand()%100;
        ind = rand()%(l->length + 2);
        switch(op) {
            case 0:
            case 1:{
                printf("insert %d at %d to Linklist = %d\n", val, ind, insert(l, ind, val));
            }break;
            case 2: {
                printf("erase %d from Linklist = %d\n", ind, erase(l, ind));
            }
        }
        output(l);
        printf("\n");
    }
    clear_linklist(l);
    return 0;
}

