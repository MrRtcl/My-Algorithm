#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
#define MAX 100050
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
    int to;
    node *next;
}*head[MAX];

void addedge(int a,int b){              //加边
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

/*线段树操作*/
void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int ln,int rn){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt]*ln;
        sum[rt<<1|1] += add[rt]*rn;
        add[rt] = 0;
    }
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

void update(int L,int R,ll C,int l,int r,int rt){
    if(L <= l && r <= R){
        sum[rt] += C*(r-l+1);
        add[rt] += C;
        return;
    }
    int m = (l+r) >> 1;
    pushdown(rt,m-l+1,r-m);
    if(L <= m) update(L,R,C,l,m,rt<<1);
    if(R > m) update(L,R,C,m+1,r,rt<<1|1);
    pushup(rt);
}

ll query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l+r)>>1;
    pushdown(rt,m-l+1,r-m);
    ll ans = 0;
    if(L <= m){
        ans += query(L,R,l,m,rt<<1);
        ans %= mod;
    }
    if(R > m){
        ans += query(L,R,m+1,r,rt<<1|1);
        ans %= mod;
    }
    return ans%mod;
}

/*树剖部分*/

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

void update_link(int a,int b,int c){
    while(top[a] != top[b]){
        if(deep[top[a]] < deep[top[b]])
            swap(a,b);
        update(dfsx[top[a]],dfsx[a],c,1,n,1);
        a = fa[top[a]];
    }
    if(deep[a] > deep[b])
        swap(a,b);
    update(dfsx[a],dfsx[b],c,1,n,1);
}

void update_tree(int a,int c){
    int s = dfsx[a];
    int e = endx[a];
    update(s,e,c,1,n,1);
}

ll find_link(int a,int b){
    ll ans = 0;
    while(top[a] != top[b]){
        if(deep[top[a]] < deep[top[b]])
            swap(a,b);
        ans += query(dfsx[top[a]],dfsx[a],1,n,1);
        ans %= mod;
        a = fa[top[a]];
    }
    if(deep[a] > deep[b])
        swap(a,b);
    ans += query(dfsx[a],dfsx[b],1,n,1);
    return ans%mod;
}

ll find_tree(int x){
    int s = dfsx[x];
    int e = endx[x];
    return query(s,e,1,n,1);
}

int main(){
    freopen("data.in","r",stdin);
    n = read();
    m = read();
    r = read();
    mod = read();
    for(register int i=1;i<=n;i++){
        arr[i] = read();
    }
    for(register int i=1;i<n;i++){
        int x,y;
        x = read();
        y = read();
        addedge(x,y);
        addedge(y,x);
    }
    dfs1(r);
    dfs2(r,r);
    build(1,n,1);
    while(m--){
        int com;
        com = read();
        switch(com){
            case 1:{
                int x,y,z;
                x = read();
                y = read();
                z = read();
                update_link(x,y,z);
                break;
            }
            case 2:{
                int x,y;
                x = read();
                y = read();
                cout << find_link(x,y) << endl;
                break;
            }
            case 3:{
                int x,y;
                x = read();
                y = read();
                update_tree(x,y);
                break;
            }
            case 4:{
                int x;
                x = read();
                cout << find_tree(x) << endl;
                break;
            }
        }
    }
    return 0;
}
