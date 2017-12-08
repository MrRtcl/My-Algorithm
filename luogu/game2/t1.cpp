#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[100],k,n,h;
int cnt[1<<20],dna[5000030];
char str[5000030];

int main(){
    freopen("data.in","r",stdin);
    scanf("%s",str);
    scanf("%d",&k);
    n = strlen(str);
    f['A'] = 0;
    f['T'] = 1;
    f['C'] = 2;
    f['G'] = 3;
    for(register int i = 0;i < n;i++){
        dna[i] = f[str[i]];
    }
    for(register int i = 0;i <= n-k;i++){
        for(register int j = 0;j < k;j++){
            h = h<<2|dna[i+j];
        }
        ++cnt[h];
        h = 0;
    }
    int maxx = -1;
    for(register int i = 0;i <= 1<<20;i++){
        maxx = max(maxx,cnt[i]);
    }
    printf("%d",maxx);
    return 0;
}