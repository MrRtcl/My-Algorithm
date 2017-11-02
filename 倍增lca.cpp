#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int deep[500050],anc[500050][20],n,s,cnt;
bool vis[500050];
struct node{
    int to;
    node *next;
}ss[1000050];
node *head[500050];

int read(){
    int x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(chr >= '0' && chr <= '9'){
        x = (x << 3) + (x << 1) + chr - '0';
        chr = getchar();
    }
    return x*w;
}

void addedge(int a,int b){
    node *t = &ss[++cnt];
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

void dfs(int x){
    vis[x] = 1;
    node *t = head[x];
    while(t){
        if(!vis[t->to]){
            deep[t->to] = deep[x]+1;
            anc[t->to][0] = x;
            dfs(t->to);
        }
        t = t->next;
    }
}

void init(){
    for(register int j=1;(1<<j)<=n;j++){
        for(register int i=1;i<=n;i++){
            if(anc[i][j-1])
                anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

int lca(int a,int b){
    register int i,j;
    if(deep[a] < deep[b]) swap(a,b);
    for(i=1;(1<<i)<=deep[a];++i);
    --i;
    for(j=i;j>=0;--j)
        if(deep[a]-(1<<j)>=deep[b])
            a = anc[a][j];
    if(a==b) return a;
    for(j=i;j>=0;--j)
        if(anc[a][j]!=anc[b][j]){
            a = anc[a][j];
            b = anc[b][j];
        }
    return anc[a][0];
}

int main(){
    n = read();
    register int m = read();
    s = read();
    for(register int i=1;i<n;i++){
        int a,b;
        a = read();
        b = read();
        addedge(a,b);
        addedge(b,a);
    }
    dfs(s);
    init();
    while(m--){
        int x,y;
        x = read();
        y = read();
        cout << lca(x,y) << endl;
    }
    return 0;
}