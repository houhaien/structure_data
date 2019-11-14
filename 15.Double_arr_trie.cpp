/*************************************************************************
	> File Name: 15.Double_arr_trie.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月14日 星期四 11时17分39秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

//排序，递归

typedef struct Node{
    int flag;
    struct Node *next[26];
}Node;

typedef struct DATNode{
    int base, check;
}DATNode;

Node *getNewNode() {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->flag = 0;
    return p;
}

int insert(Node *node, const char *str) {
    Node *p = node;
    int cnt = 0;
    for (int i = 0; str[i]; i++) {
        if (p->next[str[i] - 'a'] == NULL) {
            p->next[str[i] - 'a'] = getNewNode();
            cnt += 1;
        }
        p = p->next[str[i] - 'a'];
    }
    p->flag = 1;
    return cnt;
}

void clear(Node *node) {
    if (node == NULL) return ;
    for (int i = 0; i < 26; i++) {
        clear(node->next[i]);
    }
    free(node);
    return ;
}

int getBase(Node *node, DATNode *trie) {
    int base = 0, flag = 0;//找没找到合法的base值
    while (!flag) {
        flag = 1;
        base += 1;
        for (int i = 0; i < 26; i++) {
            if (node->next[i] == NULL) continue;
            if (trie[base + i].check == 0) continue;
            flag = 0;
            break;
        }
    }
    return base;
}

//返回最大的节点坐标
int  Transfrom(Node *node, DATNode *trie, int ind) {
    if (ind == 1) trie[ind].check = 1;
    if (node->flag) trie[ind].check = -trie[ind].check;//取反
    trie[ind].base = getBase(node, trie);
    for (int i = 0; i < 26; i++) {
        //当前节点没有第i孩子
        if (node->next[i] == NULL) continue;
        //base值加check值等于子节点的编号
        trie[trie[ind].base +i].check = ind;
    }
    int ret = ind;
    for (int i = 0; i < 26; i++) {
        if (node->next[i] == NULL) continue;
        int temp =Transfrom(node->next[i], trie, trie[ind].base + i);
        if (temp > ret) ret = temp;
    }
    return ret;
}

int search(DATNode *trie, const char *str) {
    int p = 1;
    for ( int i = 0; str[i]; i++) {
        int delta = str[i] - 'a';
        int check = abs(trie[trie[p].base + delta].check);
        if (check - p) return 0;
        p = trie[p].base + delta;
    }
    return trie[p].check < 0;
}

int main() {
    int n, cnt1 = 1, cnt2 = 0;
    char str[100];
    Node *root = getNewNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", str);
        cnt1 += insert(root, str);
    }
    DATNode *trie = (DATNode *)calloc(sizeof(DATNode), cnt1 * 10);
    cnt2 = Transfrom(root, trie, 1);//将root字典树，转化成双数组的字典树,root节点的节点编号
    while (scanf("%s", str) != EOF) {
        printf("search %s = %d\n", str, search(trie, str));
    }
    printf("Normal trie : %d\n", cnt1 * sizeof(Node));
    printf("Double trie : %d\n", cnt2 * sizeof(DATNode));
    for (int i = 0; i < cnt2; i++) {
        printf("%d %d %d\n", i, trie[i].base, trie[i].check);
    }
    return 0;
}

