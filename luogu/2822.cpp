#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#define MAX 3000
using namespace std;
long long int m,n,f[MAX][MAX],s[MAX][MAX],k,t;
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
 //   freopen("data.in","r",stdin);
 //   freopen("data.out","w",stdout);
    t = read();
    k = read();
    f[0][0] = 1;
    for(register int i = 1;i<=2003;i++){
        f[i][i] = 1;
        f[i][0] = 1;
    }
    for(register int i = 1;i<=2003;i++){
        for(register int j = 1;j<i;j++){
            f[i][j] = (f[i-1][j-1]+f[i-1][j])%k;
        }
    }
    for(register int i = 1;i<=2003;i++){
        for(register int j = 1;j<=i;j++){
            s[i][j] = s[i][j-1];
            if(f[i][j] == 0){
                s[i][j]++;
            }
        }
    }
    // for(register int i = 1;i<=2003;i++){
    //     for(register int j = 1;j<i;j++){
    //         printf("%d ",s[i][j]);
    //     }
    //     printf("\n");
    // }
    while(t--){
        n = read();
        m = read();
        m = min(n,m);
        long long int ans = 0;
        for (long long int i=1;i<=n;i++){
            long long int j = min(i,m);
            ans += s[i][j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}