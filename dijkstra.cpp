#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int w,to;
	node *next;
};
node *head[3000];
int m,n,x1,y1,dis[3000];
bool vis[3000];
struct edge{
	int dis,d;
	edge(){}
	edge(int a,int b){
		dis = a;
		d = b;
	}
	bool operator < (const edge &  a) const{
		return dis > a.dis;
	}
};

void addedge(int a,int b,int w){
	node *t = new node;
	t->next = head[a];
	t->w = w;
	t->to = b;
	head[a] = t;
}

void dijkstra(int s){
	priority_queue<edge> qu;
	dis[s] = 0;
	qu.push(edge(dis[s],s));
	while(!qu.empty()){
		edge tmp = qu.top();qu.pop();
		int u = tmp.d;
		if(vis[u]) continue;
		vis[u] = 1;
		node *t = head[u];
		while(t){
			if(!vis[t->to]&&dis[t->to]>dis[u]+t->w){
				dis[t->to] = dis[u]+t->w;
				qu.push(edge(dis[t->to],t->to));
			}
			t = t->next;
		}
	}
}

int main(){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	cin >> n >> x1 >> y1;
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		if(i-k>=1)
			addedge(i,i-k,1);
		if(i+k<=n)
			addedge(i,i+k,1);
	}
	dijkstra(x1);
	if(!vis[y1]){
		cout << -1 << endl;
		return 0;
	}
	cout << dis[y1] << endl;
	return 0;
}