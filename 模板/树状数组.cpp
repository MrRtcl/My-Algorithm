#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 500020
using namespace std;
int n,m,tree[MAX<<1];
inline int read(){
    register int x = 0 ,w = 1;
    register char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
        chr = getchar();
    }
    return x*w;
}

int lowbit(int k){
    return k&-k;
}

void add(int k,int c){
    for(;k <= n;k += lowbit(k)){
        tree[k] += c;
    }
}

int query(int k){
    int ans = 0;
    for(;k >= 1;k -= lowbit(k)){
        ans += tree[k];
    }
    return ans;
}

int main(){
    freopen("data.in","r",stdin);
    n = read(), m = read();
    for(register int i = 1;i <= n;++i){
        int a = read();
        add(i,a);
    }
    int cmd;
    while(m--){
        cmd = read();
        if(cmd == 1){
            int x = read(), k = read();
            add(x,k);
        }else{
            int x = read(), y = read();
            int tmp1 = query(x-1);
            int tmp2 = query(y);
            printf("%d\n",tmp2-tmp1);
        }
    }
    return 0;
}