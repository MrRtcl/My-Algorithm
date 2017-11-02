#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 2000
using namespace std;
int sum[MAX<<1],n,m;
struct BIT{
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
}

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

int main(){
    freopen("data.in","r",stdin);

    return 0;
}