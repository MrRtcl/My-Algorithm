#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#define MAX 100050
#define INPUT "A.in"
using namespace std;
int n;
int vis[MAX];   //在这个位置上有多少条

// inline int read(){
//     register int x = 0,w = 1;
//     register char chr = 0;
//     while(!isdigit(chr)){
//         if(chr == '-'){
//             w = -1;
//         }
//         chr = getchar();
//     }
//     while(isdigit(chr)){
//         x = x*10 + chr - '0';
//     }
//     return x*w;
// }

inline void file(){
    freopen(INPUT,"r",stdin);
}

int main(){
    // file();
    scanf("%d",&n);
    for(register int i = 1;i <= n;i++){
        char chr[100];
        cin >> chr;
        for(register int j = 0;j < strlen(chr);j++){
            if(chr[j] == '_'){
                vis[j]++;
            }
        }
    }
    int maxx = -0x3f3f3f3f;
    for(register int i = 0;i <= 90;i++){
        maxx = max(maxx,vis[i]);
    }
    if(maxx == 1)
        maxx = 0;
    printf("%d",maxx);
    return 0;
}