#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define MAX 100
using namespace std;
ll sum[MAX<<2],arr[MAX],rank[MAX],add[MAX<<2];     //线段树所用变量
int size[MAX],son[MAX],deep[MAX],fa[MAX],top[MAX];  //树剖所用变量
int m,n,r,mod,dfsx[MAX],endx[MAX],tot;                  //其他变量

ll read(){
    ll x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if(chr == '-')
            w =-1;
        chr = getchar();
    }
    while(chr >= '0' && chr <= '9'){
        x = (x<<3)+(x<<1)+chr-'0';
        chr = getchar();
    }
    return x*w;
}

struct node{
    int to,w;
    node *next;
}*head[MAX];

void addedge(int a,int b,int w){              //加边
    node *t = new node;
    t->next = head[a];
    t->to = b;
    t->w = w;
    head[a] = t;
}

/*线段树操作*/
void pushup(int rt){
    sum[rt] = min(sum[rt<<1],sum[rt<<1|1]);
}

void build(int l,int r,int rt){
    if(l == r){
        sum[rt] = rank[l];
        return;
    }
    int m = (l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

ll query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    ll ans = 0x3f3f3f3f;
    if(L <= m){
      ans = min(ans,query(L,R,l,m,rt<<1));
    }
    if(R > m){
      ans = min(ans,query(L,R,m+1,r,rt<<1|1));
    }
    return ans;
}

/*树剖部分*/

void dfs1(int x){
    size[x] = 1;
    for(register node *t = head[x];t;t=t->next){
        if(t->to == fa[x]) continue;
        arr[t->to] = t->w;
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
    rank[tot] = arr[x];
    top[x] = tp;
    if(son[x]) dfs2(son[x],tp);
    for(register node *t = head[x];t;t=t->next){
        if(t->to == fa[x] || t->to == son[x]) continue;
        dfs2(t->to,t->to);
    }
    endx[x] = tot;
}

/*正儿八经的操作*/

ll find_link(int a,int b){
    ll ans = 0x3f3f3f3f;
    while(top[a] != top[b]){
        if(deep[top[a]] < deep[top[b]])
            swap(a,b);
        ans = min(ans,query(dfsx[top[a]],dfsx[a],1,n,1));
        a = fa[top[a]];
    }
    if(deep[a] > deep[b])
        swap(a,b);
    ans = min(ans,query(dfsx[b],dfsx[b],1,n,1));
    return ans;
}

int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    n = read();
    m = read();
    for(int i = 1;i < n;i++){
      int a = read(),b = read(),w = read();
      addedge(a,b,w);
      addedge(b,a,w);
    }
    arr[1] = 0x3f3f3f3f;
    dfs1(1);
    dfs2(1,1);
    build(1,n,1);
    while(m--){
      int x = read(),y = read();
      int ans = find_link(x,y);
      cout << ans << endl;
    }
    return 0;
}