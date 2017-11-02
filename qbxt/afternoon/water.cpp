#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;
int n,ans;
inline int read(){
    register int  x = 0,w = 1;
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

struct node{
    int x,y;
}arr1[MAX],arr2[MAX];

bool cmp(node a,node b){
    if(a.x == b.x){
        return a.y > b.y;
    }
    return a.x > b.x;
}

int main(){
//    freopen("water.in","r",stdin);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr1[i].x >> arr1[i].y;
    }
    for(int i = 1;i <= n;i++){
        cin >> arr2[i].x >> arr2[i].y;
    }
    sort(arr1+1,arr1+n+1,cmp);
    sort(arr2+1,arr2+1+n,cmp);
    int now1 = 1,now2 = 1;
    while(now1 <= n && now2 <= n){
        while(arr1[now1].x < arr2[now2].x || arr1[now1].y < arr2[now2].y){
            now2++;
        }
        ans++;
        now1++;
        now2++;
    }
    cout << ans << endl;
    return 0;
}