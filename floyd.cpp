#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#define inf 0x3f3f3f3f
using namespace std;
int pic[100][100],dis[100],m,n;

void floyd(){
	for(int k=0;k<m;k++)
		for(int i=0;i<m;i++)
			for(int j=0;j<m;j++){
				if(pic[i][j] > pic[i][k]+pic[k][j])
					pic[i][j] = pic[i][k]+pic[k][j];
			}
}

int main(int argc, char const *argv[])
{
	freopen("mytools/data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin >> m >> n;
	memset(pic,inf,sizeof(pic));
	for(int i=0;i<m;i++)
		pic[i][i] = 0;
	for(int i=1;i<=n;i++){
		int a,b,w;
		cin >> a >> b >> w;
		pic[a][b] = pic[b][a] = w;
	}
	floyd();
	for(int i=0;i<m;i++){
		cout << "0->" << i << ":" << pic[0][i] << endl;
	}
	return 0;
}