/*************************************************************************
	> File Name: 10.heap_sort.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月18日 星期五 11时21分05秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <time.h>
using namespace std;

#define swap(a,b) { \
    __typeof(a) __temp =a;\
    a = b, b = __temp;\
}

void downupdate(int *arr, int n ,int ind) {
        while((ind << 1 ) <= n ) {
            int temp = ind, l = ind << 1, r = ind << 1 | 1;
            if (arr[l] > arr[temp]) temp = l;
            if (r <= n && arr[r] > arr[temp]) temp = r;
            if (ind == temp) break;
            swap (arr[temp], arr[ind]);
            ind = temp;
        }
    return ;
}


void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; --i) {
        downupdate(arr, n, i);
    }
    for (int i = n; i > 1; --i) {
        swap(arr[1], arr[i]);
        downupdate(arr, i-1, 1);
    }
    return;
}

void output(int *arr, int n) {
    printf("arr[%d] = [" ,n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
    return ;
}


int main() {
    srand(time(0));
    int op = 20;
    int *arr = (int *) malloc (sizeof(int) *op);
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() %100;
    }
    output(arr, 20);
    heap_sort(arr, 20);
    output(arr, 20);
    return 0;
}

