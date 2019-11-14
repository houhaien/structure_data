/*************************************************************************
	> File Name: 14.trie.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月14日 星期四 11时14分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
#define BASE_CNT 26
#define BASE 'a'
typedef struct Node  {
    int flag;   // 红/白 是否独立成词
    struct Node *next[26];  // 26个英文字母
} Node;

//返回一个新的字典树节点
Node *getNewNode() {
    Node *p = (Node *)malloc(sizeof(Node));
    for (int i = 0; i  < BASE_CNT; i++) {
        p->next[i] = NULL;

    }
    p->flag = 0;//不独立成词
    return p;
}
// 字典树插入不会改变根节点
void insert(Node *node, const char *str) {
    Node *p = node;
    //int cnt = 1;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            p->next[str[i] - BASE] = getNewNode();
        }
        // 沿着相关字符的边向下走一层
        p = p->next[str[i] - BASE];
        //cnt += p->flag;
    }
    p->flag = 1;
    return ;
    
}
int search(Node *node, const char *str) {
    Node *p = node;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - BASE] == NULL) {
            return 0;
        }
        // 沿着相关字符的边向下走一层
        p = p->next[str[i] - BASE];
    }
    return p->flag;  
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < BASE_CNT; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int main() {
    Node *root = getNewNode();
    char str[100];
    int op;
    while (scanf("%d%s", &op, str) != EOF) {
        switch (op) {
            case 1: {
                printf("insert %s to trie\n", str);
                insert(root, str);
            } break;
            case 2: {
                printf("search %s from trie = %d\n", str, search(root, str));
            } break;
        }
    }
    return 0;
}

