#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define MAX 10000
using namespace std;
int tot,n,m;
int arr[MAX],val[MAX];

struct node{
    int sum;
    node *l,*r;
}*root[MAX],nodes[MAX];

void build(int l,int r,node *&rt){
    rt = &nodes[++tot];
    if(l == r)
        return;
    int m = (l+r)>>1;
    build(l,m,rt->l);
    build(m+1,r,rt->r);
}

void update(int l,int r,int x,node *&rt,node *old){
    rt = &nodes[++tot];
    *rt = *old;
    rt->sum++;
    if(l == r)
        return;
    int m = (l+r)>>1;
    if(x <= m){
        update(l,m,x,rt->l,old->l);
    }else{
        update(m+1,r,x,rt->r,old->r);
    }
}

int find(int l,int r,int k,node *L,node *R){
    if(l == r)
        return l;
    int cnt = R->l->sum - L->l->sum;
    int m = (l+r)>>1;
    if(k <= cnt){
        return find(l,m,k,L->l,R->l);
    }else{
        return find(m+1,r,k-cnt,L->r,R->r);
    }
}

int getid(int x){
    return lower_bound(arr+1,arr+1+n,x) - arr;
}

int main(){
    freopen("1.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&arr[i]);
        val[i] = arr[i];
    }
    sort(arr+1,arr+1+n);
    int cnt = unique(arr+1,arr+1+n) - arr;
    build(1,cnt,root[0]);
    for(int i = 1;i <= n;i++){
        update(1,cnt,getid(val[i]),root[i],root[i-1]);
    }
    while(m--){
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        printf("%d\n",arr[find(1,cnt,k,root[l-1],root[r])]);
    }
    return 0;
}