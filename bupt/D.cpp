#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
using namespace std;
long long int n, arr2[500020];

int C(int n, int m) 
{ 
    const int M = MOD; 
    int ans = 1; 
    for(int i=n; i>=(n-m+1); --i) 
        ans *= i; 
    while(m) 
        ans /= m--; 
    return ans % M; 
} 

int main()
{
    //freopen("D.in","r",stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        long long int ans = 0;
        for (register int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr2[i]);
        }
        ans = C(2,n)/2;
        printf("%lld\n", ans);
    }
    return 0;
}