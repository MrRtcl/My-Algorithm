#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#define MAX 1000
using namespace std;
int tot;
int n,m,s,t;
int dis[MAX];
bool vis[MAX];

struct node{
	int w,to,c;
	node *next,*pre;
}nodes[MAX],*head[MAX];

void addedge(int a,int b,int w){
	node *t = &nodes[++tot];
	node *g = &nodes[++tot];
	t->next = head[a];
	t->to = b;
	t->w = 0;
	t->c = w;
	head[a] = t;
	g->next = head[b];
	g->to = a;
	g->w = 0;
	g->c = 0;
	head[b] = g;
	t->pre = g;
	g->pre = t;
}

bool bfs(){
	memset(vis,0,sizeof(vis));
	queue<int> qu;
	qu.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while(!qu.empty()){
		int u = qu.front();qu.pop();
		for(node *t = head[u];t;t = t->next){
			if(!vis[t->to] && t->c > t->w){
				vis[t->to] = 1;
				dis[t->to] = dis[u]+1;
				qu.push(t->to);
			}
		}
	}
	return vis[t];
}

int dfs(int x,int a){
	if(x == t) return a;
	int flow = 0,ans = 0;
	for(node *t = head[x];t;t = t->next){
		if(dis[t->to] == dis[x]+1){
			flow = dfs(t->to,min(a,t->c-t->w));
			if(flow <= 0){
				continue;
			}
			t->w += flow;
			t->pre->w -= flow;
			ans += flow;
			a -= flow;
			if(a == 0)
				break;
		}
	}
	return ans;
}

void dinic(){
	int ans = 0;
	while(bfs()){
		ans += dfs(s,0x3f3f3f3f);
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for(int i = 1;i <= m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		addedge(a,b,c);
	}
	dinic();
	return 0;
}
