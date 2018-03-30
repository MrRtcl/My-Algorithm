#include <iostream>
#define MAX 1000
using namespace std;
int tot,time,n,arr[MAX];
struct node{
	int key,lazy;
	node *l,*r;
}nodes[MAX],*root[MAX];

void pushup(node *&rt){
	rt->key = rt->l->key + rt->r->key;
}

void pushdown(node *&rt,int ln,int rn){
	if(rt->lazy){
		node *newl = &nodes[++tot];
		*newl = *rt->l;
		newl->lazy += rt->lazy,newl->key += rt->lazy*ln,rt->l = newl;
		node *newr = &nodes[++tot];
		*newr = *rt->r;
		newr->lazy += rt->lazy,newr->key += rt->lazy*rn,rt->r = newr;
		rt->lazy = 0;
	}
}

node* build(int l,int r,node *&rt){
	rt = &nodes[++tot];
	if(l == r){
		rt->key = arr[l];
		return rt;
	}
	int m = (l+r)>>1;
	rt->l = build(l,m,rt->l);
	rt->r = build(m+1,r,rt->r);
	pushup(rt);
}

void update(int L,int R,int C,int l,int r,node *&rt){
	if(L <= l && r <= R){
		rt->key += C*(r-l+1);
		rt->lazy += C;
		return;
	}
	int m = (l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L <= m){
		update(L,R,C,l,m,rt->l);
	}
	if(R > m){
		update(L,R,C,m+1,r,rt->r);
	}
	pushup(rt);
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

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	build(1,n,root[0]);
	while(1){
		int cmd;
		cin >> cmd;
		if(cmd == 1){
			int l,r,tt;
			cin >> l >> r >> tt;
			cout << search(l,r,1,n,root[tt]) << endl;
		}
		if(cmd == 2){
			int l,r,x;
			cin >> l >> r >> x;
			++time;
			root[time] = new node;
			*root[time] = *root[time-1];
			update(l,r,x,1,n,root[time]);
		}
	}
	return 0;
}
