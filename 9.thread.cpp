/*************************************************************************
	> File Name: 9.thread.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月18日 星期五 11时20分12秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
using namespace std;

#define NORMAL 0
#define THREAD 1

typedef struct Node{
    int key, ltag, rtag;
    struct Node *lchild, *rchild;
}Node;

Node *getnewnode(int key) {
    Node *p = (Node *)malloc (sizeof(Node));
    p->lchild = p->rchild = NULL;
    p->key = key;
    p->ltag=p->rtag = NORMAL;
    return p;
}

Node *insert(Node *root , int key) {
    if (root == NULL) return getnewnode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root ->lchild = insert(root->lchild, key);
    return root;
}

void inorder1(Node *root) {
    if (root == NULL) return;
    if (root ->ltag == NORMAL) inorder1(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder1(root->rchild);
    return;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder(root->rchild);
    return ;
}

void build_thread(Node * root) {
    if (root == NULL) return ;
    // 
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root -> lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre  != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return;
}

void clear(Node *root) {
    if (root == NULL) return;
    if (root->ltag == 0) {
        clear(root->lchild);
    }
    if (root->rtag == NORMAL) {
        clear(root->rchild);
    }
    free(root);
    return;
}
Node *leftmost(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild ) {
        p = p->lchild;
    }
    return p;
}
void output(Node *root) {
    Node *p = root;
    while (p && p->ltag == NORMAL && p->lchild ) {
        p = p->lchild;
    }
    // Node *p = leftmost(root);
    while(p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = leftmost(p->rchild);
        }
    }
    printf("\n");
    return;
}



int main() {
    Node *root = NULL;
    srand(time(0));

    for (int i = 0;  i < 20; i++) {
        int val = rand() %100;
        root = insert(root, val);
    }
    build_thread(root);
    printf("线索化 : ");
    output(root);
    printf("中序遍历 :"); 
    inorder(root);
    printf("\n");
    clear(root);
    return 0;
}


