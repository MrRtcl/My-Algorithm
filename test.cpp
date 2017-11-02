#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 2000
using namespace std;
int n,m;
struct BIT{
    int sum[MAX<<1],arr[MAX];
    int lowbit(int x){
        return x&(-x);
    }
    
    int add(int k,int c){
        for(;k <= n;k += lowbit(k)){
            sum[k] += c;
        }
    }
    
    int query(int k){
        int ans = 0;
        for(;k;k -= lowbit(k)){
            ans += sum[k];
        }
        return ans;
    }
}tree;

struct node{
    int to;
    node *next;
}*head[MAX];

inline int read(){
    int w=1,x=0;
    char c=0;
    while(c<'0'||c>'9'){
        if(c=='-')
            w = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        x = (x<<3)+(x<<1)+c-'0';
        c = getchar(); 
    }
    return w*x;
}

inline void addedge(int a,int b){
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

int main(){
    freopen("data.in","r",stdin);
    n = read(),m = read();
    for(register int i = 1; i < n;i++){
        int a = read(),b = read();
        addedge(a,b);
        addedge(b,a);
        tree.arr[i+1] = 1;
    }
    for(register int i = 1; i <= n;i++){
        tree.add(i,tree.arr[i]);
    }
    return 0;
}