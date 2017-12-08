#include <iostream>
#include <cctype>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 200020
using namespace std;
int m,n,siden,mst,f[MAX];
struct edges{
    int pre,next,w;
}edge[MAX];

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

bool cmp(edges a,edges b){
    return a.w < b.w;
}

int search(int x){
    return x == f[x] ? x : f[x] = search(f[x]);
}

int main(){
    freopen("data.in","r",stdin);
    n = read();
    m = read();
    for(register int i = 1;i <= m;i++){
        edge[i].pre = read();
        edge[i].next = read();
        edge[i].w = read();
    }
    for(register int i = 1;i <= n;i++){
        f[i] = i;
    }
    sort(edge+1,edge+m+1,cmp);
    int siden = 0;
    for(register int i = 1;i <= m;i++){
        int fa = search(edge[i].pre);
        int fb = search(edge[i].next);
        if(fa != fb){
            f[fa] = fb;
            mst += edge[i].w;
            siden++;
            if(siden == n-1){
                break;
            }
        }
    }
    int tot = 0;
    for(register int i = 1;i <= n;i++){
        if(f[i] == i){
            ++tot;
        }
    }
    if(tot > 1){
        printf("orz\n");
        return 0;
    }
    printf("%d\n",mst);
    return 0;
}