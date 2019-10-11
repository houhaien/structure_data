/*************************************************************************
	> File Name: 6.最大矩形面积.cpp
	> Author: houhaien 
	> Mail: github.com/houhaien 
	> Created Time: 2019年10月11日 星期五 10时43分24秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

#define MAXN 100000
long long arr[MAXN + 5];
long long l[MAXN + 5], r[MAXN + 5];

int main() {
    int n;
    cin >> n;
    stack<int> s;
    arr[0] = arr[n + 1] = -1;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    s.push(0);
    for (int i = 1; i<= n; i++) {
        while(arr[s.top()] >= arr[i]) s.pop();
        l[i] = i - s.top();
        s.push(i);
    }
    
    while(!s.empty()) s.pop();
    s.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while(arr[s.top()] >= arr[i]) s.pop();
        r[i] = s.top() - i;
        s.push(i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, arr[i] *(r[i] + l[i] - 1));
    }
    cout << ans << endl;
    return 0;


}
