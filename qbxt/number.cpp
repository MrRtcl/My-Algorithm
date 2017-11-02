#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 2000
using namespace std;
int sum[MAX<<2],n,t;
bool flag = 0;
struct node{
    int x,y;
}arr[MAX];

inline int read(){
    int x = 0,w = 1;
    char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
    }
}

void update(int L,int R,int C,int l,int r,int rt){
    if(L <= l && r <= R){
        sum[rt] = C;
        return;
    }
    int m = (l+r)>>1;;
    if(L <= m)  update(L,R,C,l,m,rt<<1);
    if(R > m)   update(L,R,C,m+1,r,rt<<1|1);
    sum[rt] = min(sum[rt<<1],sum[rt<<1|1]);
}

int query(int L,int R,int C,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    int ans = 0x3f3f3f3f;
    if(L <= m) ans = min(ans,query(L,R,l,m,rt<<1));
    if(R > m) ans = min(ans,query(L,R,m+1,r,rt<<1|1));
    if(sum[rt] < ans){
        flag = 1;
    }
    return ans;
}

int main(){
    n = read(),t = read();
    for(register int i = 1;i <= t;i++){
        int a = read(),b = read(),c = read();
        query(a,b,1,n,1);
        update(a,b,c,1,n,1);
    }
    for(register int i = 1;i <= t;i++){
        
    }
    return 0;
}