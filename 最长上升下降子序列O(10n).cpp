#include <iostream>             //最长上升子序列 与 最长下降子序列 要求O(nlogn) 
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <queue>
#define INPUT "C.in"
using namespace std;

int str1[100050],dp1[100050],dp2[100050];
int n;
bool vis[10];
struct node{
    int d,pos;
}num1[10],num2[10];

inline int read(){
    register int x = 0,w = 1;
    register char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-'){
            w = -1;
        }
        chr = getchar();
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
        chr = getchar();
    }
    return x*w;
}

inline void file(){
    freopen(INPUT,"r",stdin);
}

int main(){
    // file();
    n = read();
    for(register int i = 1;i <= n;i++){
        str1[i] = read();
        dp1[i] = dp2[i] = 1;
        num1[str1[i]].d = num2[str1[i]].d = 1;
        if(vis[str1[i]]) continue;
        num1[str1[i]].pos = num2[str1[i]].pos = i;
        vis[str1[i]] = 1;
    }
    for(register int i = 2;i <= n;i++){
        int maxx1 = 0;
        int maxx2 = 0;
        for(register int j = 0;j <= str1[i];j++){
            if(num1[j].pos >= i) continue;
            maxx1 = max(maxx1,num1[j].d);
        }
        for(register int j = 9;j >= str1[i];j--){
            if(num2[j].pos >= i) continue;
            maxx2 = max(maxx2,num2[j].d);
        }
        dp1[i] = maxx1 + 1;
        dp2[i] = maxx2 + 1;
        dp1[n+1] = max(dp1[i],dp1[n+1]);
        dp2[n+1] = max(dp2[i],dp2[n+1]);
        dp1[n] = max(dp1[i],dp1[n+1]);
        dp2[n] = max(dp2[i],dp2[n+1]);
        num1[str1[i]].d = dp1[i];
        num2[str1[i]].d = dp2[i];
        num1[str1[i]].pos = num2[str1[i]].pos = i;
    }
    // cout << dp1[n] << " " << dp2[n] << endl;
    cout << min(n-dp1[n],n-dp2[n]) << endl;
    return 0;
}