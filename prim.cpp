#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m,n,mst,pic[100][100];
bool flag[100];

void prim(){
	int min[100];
	memset(min,0x3f3f3f3f,sizeof(min));
	min[0] = 0;
	for(int i=0;i<m;i++){
		int minn = 0x3f3f3f3f;
		int k=0x3f3f3f3f;
		for(int j=0;j<m;j++)
			if(!flag[j] && min[j] < minn){
				minn = min[j];
				k = j;
			}
		flag[k] = 1;
		mst += min[k];
		cout << k << "-->";
		for(int j=0;j<m;j++){
			if(pic[k][j] < min[j])
				min[j] = pic[k][j];
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("mytools/data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin >> m >> n;
	memset(pic,0x3f3f3f3f,sizeof(pic));
	for(int i=0;i<m;i++)
		pic[i][i] = 0;
	for(int i=0;i<n;i++){
		int a,b,w;
		cin >> a >> b >> w;
		pic[a][b] = pic[b][a] = w;
	}
	prim();
	cout << "\n" << mst;
	return 0;
}