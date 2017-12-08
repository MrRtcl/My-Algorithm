#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 300
using namespace std;
int n,m;
long long int sum[MAX<<2],add1[MAX<<2],add2[MAX<<2],arr[MAX],mod;
inline long long int read(){
    register long long int x = 0 ,w = 1;
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

void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int ln,int rn){
    if(add2[rt] != 1){
        add1[rt<<1] *= add2[rt];
        add1[rt<<1|1] *= add2[rt];
        add2[rt<<1] *= add2[rt];
        add2[rt<<1] %= mod;
        add2[rt<<1|1] *= add2[rt];
        add2[rt<<1|1] %= mod;
        sum[rt<<1] *= add2[rt];
        sum[rt<<1] %= mod;
        sum[rt<<1|1] *= add2[rt];
        sum[rt<<1|1] %= mod;
        add2[rt] = 1;
    }
    if(add1[rt]){
        add1[rt<<1] += add1[rt];
        add1[rt<<1|1] += add1[rt];
        sum[rt<<1] += add1[rt];
        sum[rt<<1] %= mod;
        sum[rt<<1|1] += add1[rt];
        sum[rt<<1|1] %= mod;
        add1[rt] = 0;   
    }
}

void build(int l,int r,int rt){
    add2[rt] = 1;
    if(l == r){
        sum[rt] = arr[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

void update1(int L,int R,int C,int l,int r,int rt){         //加
    if(L <= l && r <= R){
        sum[rt] += C*(r-l+1);
        add1[rt] += C;   
        return;
    }
    int m = (l+r)>>1;
    pushdown(rt,m-l+1,r-l);
    if(L <= m) update1(L,R,C,l,m,rt<<1);
    if(R > m) update1(L,R,C,m+1,r,rt<<1);
    pushup(rt);
}

void update2(int L,int R,int C,int l,int r,int rt){
    if(L <= l && r <= R){
        sum[rt] *= C;
        sum[rt] %= mod;
        add2[rt] *= C;
        return;
    }
    int m = (l+r)>>1;
    pushdown(rt,m-l+1,r-m);
    if(L <= m) update2(L,R,C,l,m,rt<<1);
    if(R > m) update2(L,R,C,m+1,r,rt<<1);
    pushup(rt);
}

long long int query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    pushdown(rt,m-l+1,r-m);
    long long int ans = 0;
    if(L <= m) ans = (ans%mod+query(L,R,l,m,rt<<1)%mod)%mod;
    if(R > m) ans = (ans%mod+query(L,R,m+1,r,rt<<1|1)%mod)%mod;
    return ans;
}

int main(){
    freopen("data.in","r",stdin);
    n = read(),m = read(),mod = read();
    for(register int i = 1;i <= n;++i){
        arr[i] = read();
    }
    build(1,n,1);
    int cmd;
    while(m--){
        cmd = read();
        if(cmd == 1){
            int x = read(),y = read(),k = read();
            update2(x,y,k,1,n,1);
        }else if(cmd == 2){
            int x = read(),y = read(),k = read();
            update1(x,y,k,1,n,1);
        }else{
            int x = read(),y = read();
            printf("%lld\n",query(x,y,1,n,1));
        }
    }
    return 0;
}