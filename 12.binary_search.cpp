/*************************************************************************
	> File Name: 12.binary_search.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年11月14日 星期四 11时10分53秒
 ************************************************************************/

#include <stdio.h>
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

//12345
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] > x) tail = mid - 1;
        else head = mid + 1;
    }
    return -1;
}

//11111000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        //这样在最后剩两个数取最后一个数，避免死循环
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

//0000111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 1) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}


int main() {
    int a[10] = {1, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int b[10] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
    int c[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1};
    P(binary_search1(a, 10, 11));
    P(binary_search2(b, 10));
    P(binary_search3(c, 10));
    return 0;
}

