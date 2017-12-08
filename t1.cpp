#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <map>
#define MAX 200
using namespace std;
long long int num[MAX],n,ans;
map<long long int,long long int> mp;
map <long long int ,long long int>::iterator it;

int main(){
    freopen("data.in","r",stdin);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= n;k++){
                int tmp = num[i]*num[j]+num[k];
                it = mp.find(tmp);
                if(it == mp.end()){
                    mp.insert(make_pair(tmp,1));
                }else{
                    it->second++;
                }
            }
    for(int i = 1;i <= n;i++){
        if(num[i] == 0) continue;
        for(int j = 1;j <= n;j++)
            for(int k = 1;k <= n;k++){
                int tmp = num[i]*(num[j]+num[k]);
                it = mp.find(tmp);
                if(it == mp.end())
                    continue;
                ans += it->second;
            }
    }
    cout << ans << endl;
    return 0;
}