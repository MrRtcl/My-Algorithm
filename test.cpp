#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX 2000
using namespace std;
int sum[MAX<<1],n,m;
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

int main(){
    freopen("data.in","r",stdin);
    cin >> n >> m;
    for(register int i = 1;i <= n;i++){
        int a;
        cin >> a;
        add(i,a);
    }
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            add(b,c);
        }else{
            int tmp1 = query(b-1);
            int tmp2 = query(c);
            cout << tmp2-tmp1 << endl;
        }
    }
    return 0;
}