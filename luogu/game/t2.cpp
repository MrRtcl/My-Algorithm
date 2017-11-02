#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <algorithm>
#define MAX 300000
using namespace std;
int n,arr[MAX],m,color[MAX];
inline int read(){
    int x = 0, w = 1;
    char chr = 0;
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
    //freopen("data.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&arr[i]);
        color[arr[i]]++;
    }
    int cmd;
    while(m--){
        scanf("%d",&cmd);
        if(cmd == 1){
            int l,r,c;
            scanf("%d %d %d",&l,&r,&c);
            int ans = 0,temp = 0;
            if((r-l) <= n-20){
                for(int i = 1; i < l;i++){
                    if(arr[i] == c){
                        temp++;
                    }
                }
                for(int i = r+1;i <= n;i++){
                    if(arr[i] == c){
                        temp++;
                    }
                }
                ans = (color[c] - temp);
                printf("%d\n",ans);
                continue;
            }
            for(int i = l;i <= r;i++){
                if(arr[i] == c){
                    ans++;
                }
            }
            printf("%d\n",ans);
        }else{
            int j = read();
            swap(arr[j],arr[j+1]);
        }
    }
    return 0;
}