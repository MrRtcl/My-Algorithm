#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#define MAX 1000020
using namespace std;
int t;
long long int nums[MAX],n;
inline long long int read(){
    register long long int  x = 0,w = 1;
    register char chr = 0;
    while(!isdigit(chr)){
        if(chr == '-'){
            w = -1;
        }
        chr = getchar();
    }
    while(isdigit(chr)){
        x = x*10 + chr - '0';
        chr = getchar();
    }
    return x*w;
} 

inline long long int pow(long long int a,long long int b){
    register long long int r = 1;
    while(b){
        if(b&1){
            r = r*a;
        }
        a = a*a;
        b = b>>1;
    }
    return r;
}

void make_columns(){
    for(register int i = 1;i <= MAX;i++){
        nums[i] = pow(i,3);
    }
}

int main(){
    freopen("cubic.in","r",stdin);
    freopen("cubic.out","w",stdout);
    t = read();
    make_columns();
    while(t--){
        n = read();
        int pos = lower_bound(nums+1,nums+MAX,n)-nums;
        if(nums[pos] == n){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}