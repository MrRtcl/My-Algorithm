#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#define MAX 10050
using namespace std;
int instack[MAX],dfn[MAX],low[MAX],index,m,n;
int SSCcnt,belong[MAX];
stack<int> st;
struct node{
    int w,to;
    node *next;
}*head[MAX];

void read(){
    int x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(chr >= '0' && chr <='9'){
        x = (x << 3) + (x << 1) + chr - '0';
        chr = getchar();
    }
    return x*w;
}

void addedge(int a,int b,int w){
    node *t = new node;
    t->next = head[a];
    t->w = w;
    t->to = b;
    head[a] =t;
}

void tarjan(int u){
    dfn[u] = low[u] = ++index;
    instack[u] = 1;
    st.push(u);
    for(node *t = head[u];t;t = t->next){
        if(!dfn[t->to]){
            tarjan(t->to);
            low[u] = min(low[u],low[t->to]);
        }
        else if(instack[t->to] && low[u] > dfn[t->to]){
            low[u] = dfn[t->to];
        }
    }
    if(dfn[u] == low[u]){
        int j;
        SSCcnt++;
        do{
            j = st.top();
            st.pop();
            instack[j] = 0;
            belong[j] = SSCcnt;
        }while(j != u)
    }
}

int main(){
    n = read();
    m = read();
    for(int i=1;i<=m;i++){
        int a,b,w;
        a = read();
        b = read();
        w = read();
        addedge(a,b,w);
        addedge(b,a,w);
    }
    tarjan(1);
    return 0;
}