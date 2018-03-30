#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 50000
using namespace std;
int n,m,s,t;
int ans1,ans2;
int vis[MAX],dis[MAX],flow[MAX];

struct node{
	int c,w,to,f;
	node *next,*pre;
}*head[MAX],*pre[MAX];

void addedge(int a,int b,int w,int f){
	node *t = new node;
	node *g = new node;
	t->next = head[a];
	t->to = b;
	t->w = w;
	t->f = f;
	head[a] = t;
	g->next = head[b];
	g->to = a;
	g->w = 0;
	g->f = -f;
	head[b] = g;
	g->pre = t;
	t->pre = g;
}

bool bfs(){
	for(int i = 1;i <= n;i++){
		pre[i] = NULL;
		dis[i] = 0x3f3f3f3f;
		vis[i] = 0;
	}
	queue<int> qu;
	dis[s] = 0;
	vis[s] = 1;
	flow[s] = 0x3f3f3f3f;
	qu.push(s);
	while(!qu.empty()){
		int u = qu.front();
		qu.pop();
		vis[u] = 0;
		for(node *t = head[u];t;t=t->next){
			if(dis[t->to] > dis[u] + t->f && t->w > 0){
				dis[t->to] = dis[u] + t->f;
				flow[t->to] = min(flow[u],t->w);
				pre[t->to] = t;
				if(!vis[t->to]){
					vis[t->to] = 1;
					qu.push(t->to);
				}
			}
		}
	}
	return dis[t] != 0x3f3f3f3f;
}

void EK(){
	ans1 = ans2 = 0;
	while(bfs()){
		int k = t;
		while(k != s){
			node *g = pre[k];
			g->w -= flow[t];
			g->pre->w += flow[t];
			k = g->pre->to;
		}
		ans1 += flow[t];
		ans2 += flow[t]*dis[t];
	}
	cout << ans1 << " " << ans2 << endl;
}

int main(){
	cin >> n >> m >> s >> t;
	for(int i = 1;i <= m;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		addedge(a,b,c,d);
	}
	EK();
	return 0;
}
