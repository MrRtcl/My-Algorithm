#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <algorithm>
#define INPUT "B.in"
using namespace std;

int num[110];
int pic[110][110];
int pic2[110][110];
int n,m;

inline int read(){
    register int x = 0,w = 1;
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

inline void file(){
    freopen(INPUT,"r",stdin);
}

inline void output1(){
    for(register int i = 1;i <= n;i++){
        for(register int j = 1;j <= n;j++){
            cout << pic[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

inline void output2(){
    for(register int i = 1;i <= n;i++){
        for(register int j = 1;j <= n;j++){
            cout << pic2[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    // file();
    n = read(),m = read();
    for(register int i = 1;i <= m;i++){
        int a = read(),b = read();
        pic[a][b] = 1;
        pic2[b][a] = 1;
    }
    // output1();
    // output2();
    for(register int k = 1;k <= n;k++){
        for(register int i = 1;i <= n;i++){
            for(register int j = 1;j <= n;j++){
                if(pic[i][k] == 1 && pic[k][j] == 1){
                    pic[i][j] = 1;
                    pic2[j][i] = 1;
                }
            }
        }
    }
    // output1();
    // output2();
    for(register int i = 1;i <= n;i++){
        for(register int j = 1;j <= n;j++){
            if(pic[i][j] == 1 || pic2[i][j] == 1){
                num[i]++;
            }
        }
    }
    int ans = 0;
    for(register int i = 1;i <= n;i++){
        // cout << num[i];
        if(num[i] >= n-1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}