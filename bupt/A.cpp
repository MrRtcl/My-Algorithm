#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#define MAX 100
using namespace std;
int used[MAX];
int arr[] = {41,42,43,44,45,46,47,48,11,19,21,29,31,39};
int T,n;
int ans;

int main(){
    // freopen("A.in","r",stdin);
    scanf("%d",&T);
    while(T--){
        ans = 0;
        memset(used,0,sizeof(used));
        for(int i = 1;i <= 13;i++){
            char ch = 0;
            while(!((ch >= 'a' && ch <= 'z') || (ch >='0' && ch <= '9')))
                ch = getchar();
            char ch1,ch2;
            int tmp = 0;
            ch1 = ch;
            scanf("%c",&ch2);
            tmp += (ch1-'a'+1)*10;
            tmp += ch2-'0';
            used[tmp]++;
        }
        for(int i = 0;i <= 13;i++){
            if(used[arr[i]] == 1){
                ans++;
            }
        }
        if(ans == 13){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}