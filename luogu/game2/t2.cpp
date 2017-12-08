#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
#define MAX 3000
using namespace std;
int n,m,C,T;
int arr[MAX],maxn = 0;
long long int f[MAX];
inline int read(){
    register int x = 0, w = 1;
    register char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
        chr = getchar();
    }
    return x*w;
}

int main(){
    freopen("data.in","r",stdin);
    n = read();
    for(int i = 1; i<= n;i++){
        arr[i] = read();
        maxn = max(maxn,arr[i]);
    }
    T = read();
    int a,b,c;
    while(T--){
        a = read(),b = read(),c = read();
        if(a > 0 && b > 0){
            printf("%d %d\n",arr[n],arr[1]);
            continue;
        }
        if(a < 0 && b < 0){
            printf("%d %d\n",arr[1],arr[n]);
            continue;
        }
        f[0] = a, f[1] = b;
        for(register int i = 2;i <= maxn;i++){
            f[i] = c*f[i-1]+f[i-2];
        }
        int pos1 , pos2 , maxx = -0x3f3f3f3f,minn = 0x3f3f3f3f;
        for(register int i = 1;i <= n;i++){
            if(f[arr[i]] > maxx){
                pos1 = arr[i];
                maxx = f[arr[i]];
            }
            if(f[arr[i]] < minn){
                pos2 = arr[i];
                minn = f[arr[i]];
            }
        }
        printf("%d %d\n",pos1,pos2);
    }
    return 0;
}