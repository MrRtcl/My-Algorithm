#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 5000050
using namespace std;
int tot,time,n,arr[MAX],num[MAX],m;
int ls[MAX],rs[MAX],sum[MAX],root[MAX];

void build(int l,int r,int &rt){
	rt = ++tot;
	sum[rt] = 0;
	if(l == r){
		return;
	}
	int m = (l+r)>>1;
	build(l,m,ls[rt]);
	build(m+1,r,rs[rt]);
}

void change(int old,int &rt,int l,int r,int p){
	rt = ++tot;
	ls[rt] = ls[old];
	rs[rt] = rs[old];
	sum[rt] = sum[old]+1;
	if(l == r){
		return;
	}
	int m = (l+r)>>1;
	if(p <= m){
		change(ls[old],ls[rt],l,m,p);
	}else{
		change(rs[old],rs[rt],m+1,r,p);
	}
}

int find(int s,int t,int l,int r,int k){
	if(l == r){
		return l;
	}
	int m = (l+r)>>1;
	int cnt = sum[ls[t]]-sum[ls[s]];
	if(k <= cnt){
		return find(ls[s],ls[t],l,m,k);
	}else{
		return find(rs[s],rs[t],m+1,r,k-cnt);
	}
}

int main(){
	freopen("1.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%d",&arr[i]);
		num[i] = arr[i];
	}
	sort(arr+1,arr+n+1);
	int cnt = unique(arr+1,arr+1+n)-arr-1;
	build(1,cnt,root[0]);
	for(int i = 1;i <= n;i++){
		num[i] = lower_bound(arr+1,arr+1+n,num[i])-arr;
	}
	for(int i = 1;i <= n;i++){
		change(root[i-1],root[i],1,cnt,num[i]);
	}
	while(m--){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",arr[find(root[a-1],root[b],1,cnt,c)]);
	}
	return 0;
}
