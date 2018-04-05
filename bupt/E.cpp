#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100005
using namespace std;
int f[MAX],pre[MAX],dfsx[MAX],endx[MAX];
int rt,n,m,tot,num;
bool flag;

struct node{
    int to;
    node *next;
}*head[MAX];

void pushup(node *&rt){
	rt->key = rt->l->key + rt->r->key;
}

node* build(int l,int r,node *&rt){
	rt = &nodes[++tot];
	if(l == r){
		rt->key = 0;
		return rt;
	}
	int m = (l+r)>>1;
    build(l,m,rt->l);
	build(m+1,r,rt->r);
}

int search(int L,int R,int l,int r,node *&rt){
	if(L <= l && r <= R){
		return rt->key;
	}
	int m = (l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	int ans = 0;
	if(L <= m){
		ans += search(L,R,l,m,rt->l);
	}
	if(R > m){
		ans += search(L,R,m+1,r,rt->r);
	}
	return ans;
}

void addedge(int a,int b){
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

void dfs(int x){
    dfsx[x] = ++tot;
    f[tot] = x;
    for(node *t = head[x];t;t=t->next){
        if(t->to == pre[x])
            continue;
        pre[t->to] = x;
        dfs(t->to);
    }
    endx[x] = tot;
}

int main(){
    scanf("%d %d",&n,&rt);
    for(int i = 1;i < n ;i++){
        arr[i] = i;
        int a,b;
        scanf("%d %d",&a,&b);
        addedge(a,b);
        addedge(b,a);
    }
    scanf("%d",&m);
    while(m--){
        char cmd[10];
        int num;
        cin >> cmd;
        scanf("%d",&num);
        if(cmd[0] == 83){
            rt = num;
            flag = 0;
        }else{
            int ans = 0;
            if(flag == 0){
                memset(f,0,sizeof(f));
                memset(pre,0,sizeof(pre));
                memset(dfsx,0,sizeof(dfsx));
                memset(endx,0,sizeof(endx));
                tot = 0;
                dfs(rt);
                flag = 1;
            }
            int s = dfsx[num],t = endx[num];
            ans = search(s,e,1,n,rt[num]);
            printf("%d\n",ans);
        }
    }
    return 0;
}