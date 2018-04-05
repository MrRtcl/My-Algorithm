#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int n;
int ans,r;

int main()
{
    // freopen("C.in","r",stdin);
    scanf("%d",&n);
    map<int, int> mp;
    r = 0 ,ans = 0;
    mp[0] = 1;
    for(int i = 1;i <= n;i++){
        int num;
        scanf("%d",&num);
        r = r^num;
        if(mp[r]){
            ans += mp[r];
            ans %= 1000000007;
        }
        mp[r]++;
    }
    printf("%d",ans);
    return 0;
}