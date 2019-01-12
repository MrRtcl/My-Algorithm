#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int pre,next,w;
}e[200050];
int m,n,mst,f[5050],siden;

int search(int x){
    return x == f[x] ? x : f[x] = search(f[x]);
}

int cmp(edge a,edge b){
    return a.w < b.w;
}

void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int fa = e[i].pre;
        int fb = e[i].next;
        if(search(fa) != search(fb)){
            f[search(fa)] = search(fb);
            mst += e[i].w;
            siden++;
        }
        if(siden == m-1)
            break;
    }
}

int main(int argc, char const *argv[])
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        e[i].pre = a;
        e[i].next = b;
        e[i].w = w;
    }
    for(int i=1;i<=n;i++){
        f[i] = i;
    }
    kruskal();
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(f[i] == i) ++ans;
        if(ans > 1){
            cout << "orz" << endl;
            return 0;
        }
    }
    cout << mst << endl;
    return 0;
}