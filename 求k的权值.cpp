#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

struct node{
    int sum;
    node *l,*r;
}*root[MAX],nodes[MAX];

void build(int l,int r,node *&rt){
    rt = nodes[++tot];
    if(l == r){
        return;
    }
    int m = (l+r)>>1;
    build(l,m,rt->l);
    build(m+1,r,rt->r);
}

int main(){

    return 0;
}