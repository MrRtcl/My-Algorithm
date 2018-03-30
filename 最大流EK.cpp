#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 1000000
using namespace std;
int tot;
int m,n,s,t,ans;
int f[MAX];

struct node{
    int w,c,f,now,to;
    node *next,*pre;
}*head[MAX],nodes[MAX],*pre[MAX];


bool bfs(){
    queue<int> qu;
    f[s] = 0x3f3f3f3f;
    for(int i = 1;i <= n;i++){
        pre[i] = NULL;
    }
    pre[s] = 0;
    qu.push(s);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(u == t){
            break;
        }
        for(node *t = head[u];t;t = t->next){
            if(pre[t->to] == NULL && t->c > t->w){
                pre[t->to] = t;
                f[t->to] = min(f[u],t->c - t->w);
                qu.push(t->to);
            }
        }
    }
    if(pre[t] == NULL){
        return false;
    }else{
        return true;
    }
}

void addedge(int a,int b,int w){
    node *t = &nodes[++tot];
    t->now = tot;
    node *g = &nodes[++tot];
    g->now = tot;
    t->next = head[a];
    head[a] = t;
    g->next = head[b];
    head[b] = g;
    t->to = b;
    g->to = a;
    t->w = 0;
    g->w = 0;
    t->c = w;
    g->c = 0;
    t->pre = g;
    g->pre = t;
}

int main(){
    cin >> n >> m >> s >> t;
    int inc;
    for(int i = 1;i <= m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        addedge(a,b,c);
    }
    while(bfs()){
        int k = t;
        while(k != s){
            node *g = pre[k];
            g->w += f[t];
            g->pre->w -= f[t];
            k = g->pre->to;
        }
        ans += f[t];
    }
    cout << ans << endl;
    return 0;
}
