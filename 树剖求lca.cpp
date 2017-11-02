#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define MAX 500050
using namespace std;
int m,n,s;
int deep[MAX],son[MAX],size[MAX],top[MAX],fa[MAX],tot,dfsx[MAX];

int read(){
    int x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if (chr == '-')
            w = -1;
        chr = getchar();
    }
    while(chr >= '0' && chr <= '9'){
        x = (x<<3)+(x<<1)+chr-'0';
        chr = getchar();
    }
    return x*w;
}

struct node{
    int to;
    node *next;
}*head[MAX];

void addedge(int a,int b){              //加边
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

void dfs1(int x){
    size[x] = 1;
    for(register node *t = head[x];t;t=t->next){
        if(t->to == fa[x]) continue;
        deep[t->to] = deep[x]+1;
        fa[t->to] = x;
        dfs1(t->to);
        size[x] += size[t->to];
        if(size[t->to] > size[ son[x] ]){
            son[x] = t->to;
        }
    }
}

void dfs2(int x,int tp){
    dfsx[x] = ++tot;
    top[x] = tp;
    if(son[x]) dfs2(son[x],tp);
    for(register node *t = head[x];t;t=t->next){
        if(t->to == fa[x] || t->to == son[x]) continue;
        dfs2(t->to,t->to);
    }
}

int lca(int a,int b){
    while(top[a] != top[b]){
        if(deep[top[a]] < deep[top[b]])
            swap(a,b);
        a = fa[top[a]];
    }
    if(deep[a] > deep[b])
        swap(a,b);
    return a;
}

int main(){
//    freopen("data.in","r",stdin);
    n = read();
    m = read();
    s = read();
    for(register int i=1;i<n;i++){
        int a,b;
        a = read();
        b = read();
        addedge(a,b);
        addedge(b,a);
    }
    dfs1(s);
    dfs2(s,s);
    while(m--){
        int a,b;
        a = read();
        b = read();
        cout << lca(a,b) << endl;
    }
    return 0;
}