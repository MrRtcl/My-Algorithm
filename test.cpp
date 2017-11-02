#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cctype>
#define MAX 300300
using namespace std;
int n,m,size[MAX],son[MAX],top[MAX],dfsx[MAX],deep[MAX],fa[MAX];
int sum[MAX<<1],arr[MAX],tot,indexx,lca;
struct node{
    int to;
    node *next;
}*head[MAX];

struct war{
    int x,y;
}tt[MAX];

inline int read(){
    int x = 0, w = 1;
    char chr = 0;
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

inline void addedge(int a,int b){
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

int lowbit(int x){
    return x&(-x);
}

int update(int k,int c){
    for(;k <= n;k += lowbit(k)){
        sum[k] += c;
    }
}

int query(int k){
    int ans = 0;
    for(;k;k -= lowbit(k)){
        ans += sum[k];
    }
    return ans;
}

inline void dfs1(int x){
    size[x] = 1;
    for(register node *t = head[x];t;t=t->next){
        if(t->to == fa[x]) continue;
        fa[t->to] = x;
        deep[t->to] = deep[x]+1;
        dfs1(t->to);
        size[x] += size[t->to];
        if(size[t->to] > size[ son[x] ]){
            son[x] = t->to;
        }
    }
}

inline void dfs2(int x,int tp){
    dfsx[x] = ++indexx;
    top[x] = tp;
    if(son[x]){
        dfs2(son[x],tp);
    }
    for(register node *t = head[x];t;t=t->next){
        if(t->to == son[x] || t->to == fa[x])
            continue;
        dfs2(t->to,t->to);
    }
}

inline void add(int a,int b,int c){
    if(deep[a] < deep[b])
        swap(a,b);
    update(dfsx[a],c);
}

inline int query_tree(int a,int b){
    int ans = 0;
    lca = 0;
    while(top[a] != top[b]){
        if(deep[top[a]] < deep[top[b]])
            swap(a,b);
        int tmp1 = query(dfsx[top[a]]-1);
        int tmp2 = query(dfsx[dfsx[a]]);
        ans += tmp2-tmp1;
        a = fa[top[a]];
    }
    if(deep[a] > deep[b])
        swap(a,b);
    int tmp1 = query(dfsx[a]-1);
    int tmp2 = query(dfsx[b]);
    ans += tmp2-tmp1;
    lca = a;
    return ans;
}

int main(){
    freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    n = read(), m = read();
    for(register int i = 1;i < n;i++){
        int a = read(),b = read();
        arr[i+1] = 1;
        addedge(a,b);
        addedge(b,a); 
    }
    for(register int i = 1;i <= n;i++){
        update(i,arr[i]);
    }
    dfs1(1);
    dfs2(1,1);
    char cmd;
    while(m--){
        cin >> cmd;
        if(cmd == 'Q'){
            int p = read(), q = read();
            int D1 = query_tree(p,q)-query(dfsx[lca]);
            int D2 = (deep[p]+deep[q])-(deep[lca]*2);
            if(D1 == D2){
                printf("Yes\n");
            }else
                printf("No\n");
        }else if(cmd == 'C'){
            int p = read(), q = read();
            tt[++tot].x = p;
            tt[tot].y = q;
            add(p,q,-1);
        }else if(cmd == 'U'){
            int x = read();
            add(tt[x].x,tt[x].y,1);
        }
    }
    return 0;
}