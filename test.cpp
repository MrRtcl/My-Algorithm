#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

inline int read(){
    register int x = 0,w = 1;
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
    int n,p;
    n = read();
    p = read();
    for(register int i = 1;i <= n;i++){
        int x,y;
        exgcd(i,p,x,y);
        while(x<0) x += p;
        printf("%d\n",x);
    }
    return 0;
}