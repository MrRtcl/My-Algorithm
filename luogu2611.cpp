#include <iostream>
#include <cstdio>
#include <stack>
#define MAX 200050
using namespace std;
int n,dfn[MAX],low[MAX],SSCcnt,belong[MAX],cnt[MAX],minn = 0x3f3f3f3f;

struct node{
    int to;
    node *next;
}*head[MAX];

void addedge(int a,int b){
    node *t = new node;
    t->to = b;
    t->next = head[a];
    head[a] = t;
}

int read(){
    int x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(chr >= '0' && chr <= '9'){
        x = (x<<3)+(x<<1)+chr-'0';
        chr = getchar();
    }
    return x*w;
}

int index,instack[MAX];
stack<int> st;

void tarjan(int u){
    dfn[u] = low[u] = ++index;
    instack[u] = 1;
    st.push(u);
    for(node *t = head[u];t;t = t->next){
        if(!dfn[t->to]){
            tarjan(t->to);
            low[u] = min(low[u],low[t->to]);
        }else if(instack[t->to]){
            low[u] = min(low[u],dfn[t->to]);
        }
    }
    if(dfn[u] == low[u]){
        SSCcnt++;
        int ans=0;
        int j;
        do{
            j = st.top();
            st.pop();
            ans++;
            instack[j] = 0;
        }while(j!=u);
        if(ans != 1)
        minn = min(minn,ans);
    }
}

int main(){
    n = read();
    for(int i=1;i<=n;i++){
        int a;
        a = read();
        addedge(i,a);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i])
        tarjan(i);
    cout << minn << endl;
    return 0;
}