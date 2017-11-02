#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n,k,m,s,t,cul[110],dis[150];
bool pic[110][110],vis[150];
struct node{
    int w,to;
    node *next;
}*head[100];

struct edge{
    int dis,d;
    edge(){}
    edge(int a,int b){
        dis = a;
        d = b;
    }
    bool operator < (const edge & a)const{
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

void init(){
    cin >> n >> k >> m >> s >> t;
    for(int i=1;i<=n;i++){
        cin >> cul[i];
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            cin >> pic[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        if(!pic[cul[a]][cul[b]]){
            addedge(a,b,w);
        }
        if(!pic[cul[b]][cul[a]]){
            addedge(b,a,w);
        }
    }
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
    init();
    for(node *t = head[1];t;t=t->next){
        cout << t->to << " ";
    }
    // dijkstra(s);
    // if(!vis[t]){
    //     cout << -1 << endl;
    //     return 0;
    // }
    // cout << dis[t] << endl;
    return 0;
}