#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#define INPUT ".in"
using namespace std;

inline int read(){
    register int x = 0,w = 1;
    register char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-'){
            w = -1;
        }
        chr = getchar()
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
    }
    return x*w;
}

inline void file(){
    freopen(INPUT,"r",stdin);
}

int main(){
    return 0;
}