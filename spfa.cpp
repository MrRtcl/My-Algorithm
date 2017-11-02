#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
	int d,w;
	node *next;
};
int m,n,dis[100];
node *head[100],*t;
bool flag[100];

void spfa(int start){
	memset(dis,inf,sizeof(dis));
	memset(flag,0,sizeof(flag));
	dis[start] = 0;
	flag[start] = 1;
	queue<int> qu;
	qu.push(start);
	while(!qu.empty()){
		int tmp = qu.front();
		qu.pop();
		t = head[tmp];
		while(t){
			if(dis[t->d] > t->w + dis[tmp]){
				dis[t->d] = t->w + dis[tmp];
				if(!flag[t->d]){
					qu.push(t->d);
					flag[t->d] = 1;
				}
			}
			t = t->next;
		}
		flag[tmp] = 0;
	}
}

void AddEdge(int a,int b,int w){
	t = new node;
	t->next = head[a];
	t->d = b;
	t->w = w;
	head[a] = t;
}

int main(){
	freopen("mytools/data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin >> m >> n;
	for(int i=0;i<n;i++){
		int a,b,w;
		cin >> a >> b >> w;
		AddEdge(a,b,w);
		AddEdge(b,a,w);
	}
	spfa(0);
	for(int i=0;i<m;i++){
		cout << "0->" << i << ":" << dis[i] << endl;
	}
	return 0;
}