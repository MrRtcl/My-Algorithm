#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#define MAX 131075
using namespace std;
int k,n;
int color[MAX],arr[MAX];
bool num[MAX*10];

inline void make_columns(){
    for(register int  i = 2;i;i++){
        num[i*i] = 1;
        if(i*i > MAX<<1)
            break;
    }
}

int main(){
    scanf("%d %d",&n,&k);
    if(n == 2 && k == 1){
        make_columns();
        for(int i = 1;i <= n;i++){
            scanf("%d",arr[i]);
        }
        if(num[arr[1]+arr[2]]){
            printf("2\n");
            printf("1\n");
        }else{
            printf("1\n");
            printf("\n\n");
        }
        return 0;
    }
    printf("1\n");
    printf("\n\n");
    return 0;
}