/*************************************************************************
	> File Name: 6.haffman.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月11日 星期五 14时55分25秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define MAXN 30000

#define swap(a,b){\
    _typeof(a) temp = a;\
    a = b, b = temp;\
}

typedef struct Node{
    char ch;
    double p;
    struct Node*next[2];
}Node;

typedef struct Code{
    char *ch;
    char *str;
}Code;

typedef struct HaffmanTree{
    Node *root;
    int n;
    Code *codes;
}HaffmanTree;

typedef struct Data {
    char ch;
    double p;
}Data;

Data arr[MAXN + 5];

int main() {

}
