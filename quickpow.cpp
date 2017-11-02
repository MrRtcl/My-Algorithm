#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int read(){
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

long long int ksm(long long int a,long long int b,long long int mod){
    long long int r=1;
    while(b){
        if(b&1)
            r = (r*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return r;
}

int main(){
    int a,b,c;
    a = read();
    b = read();
    c = read();
    cout << a << "^" << b << " mod " << c << "=" << ksm(a,b,c);
    return 0;
}