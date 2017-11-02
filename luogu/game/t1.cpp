#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
long long int f[1000];

int main(){
    int m,n;
    // freopen("data.in","r",stdin);
    f[0] = f[1] = 1;
    for(n = 2;n <= 60;n++){
        f[n] = f[n-1]+f[n-2];
    }
    scanf("%d",&m);
    long long int a,b;
    while(m--){
        scanf("%lld%lld",&a,&b);
        if(a == b){
            printf("%lld\n",a);
            continue;
        }       
        int i = 0, j = 0;
        long long int arr1[4000],arr2[4000],ans = 0;        //代表a的i层祖先
        arr1[++i] = a;
        arr2[++j] = b;
        if(a == 1){
            arr1[++i] = 1;
        }
        while(a != 1){
            int pos = lower_bound(f+1,f+60,a)-f;
            a = a - f[pos-1];
            arr1[++i] = a;
        }
        if(b == 1){
            arr2[++j] = 1;
        }
        while(b != 1){
            int pos = lower_bound(f+1,f+60,b)-f;
            b = b - f[pos-1];
            arr2[++j] = b;
        }
        int step = abs(i-j);
        int now1 = 0,now2 = 0;
        if(i > j){
            now1 = 1,now2 = 1+step;
            while(arr1[now2] != arr2[now1]){
                now1++;
                now2++;
            }
            ans = arr1[now2];
        }else if(j > i){
            now1 = 1,now2 = 1+step;
            while(arr1[now1] != arr2[now2]){
                now1++;
                now2++;
            }
            ans = arr1[now1];
        }else{
            now1 = 1;
            while(arr1[now1] != arr2[now1]){
                now1++;
            }
            ans = arr1[now1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

