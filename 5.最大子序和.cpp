/*************************************************************************
	> File Name: 5.最大子序和.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月11日 星期五 10时36分41秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 300000

int q[MAXN +5], head, tail;
long long arr[MAXN + 5];

int main() {
    long long n,m,ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    head = tail = 0;
    q[tail++] = 0;
    ans = arr[1];
    for (int i = 1; i<= n; i++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while(tail - head && arr[q[tail - 1]] >= arr[i]) {
            tail--;
        }
        q[tail++] = i;
        if (q[head] == i-m) head++;
    }
    cout << ans << endl;
    return 0;
}

