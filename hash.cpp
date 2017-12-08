#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 10000000
using namespace std;
unsigned long long int num1[MAX],num2[MAX];
int k,tot;

unsigned long long int hash(string a){
    int len = a.size();
    unsigned long long int seed = 255;
    unsigned long long int mod = 2333333;
    unsigned long long int tmp = 0;
    for(register int i = 0;i < len;i++){    
        tmp = (tmp*seed+a[i])%mod;
    }
    return tmp;
}

unsigned long long int hash2(string a){
    int len = a.size();
    unsigned long long int seed = 163;
    unsigned long long int mod = 1000007;
    unsigned long long int tmp = 0;
    for(register int i = 0;i < len;i++){    
        tmp = (tmp*seed+a[i])%mod;
    }
    return tmp;
}

int main(){
    freopen("data.in","r",stdin);
    cin >> k;
    for(register int i = 1;i <= k;i++){
        string str;
        cin >> str;
        unsigned long long int tmp1 = hash(str);
        unsigned long long int tmp2 = hash2(str);
        if(num1[tmp1] && num2[tmp2])
            continue;
        tot++;
        num1[tmp1] = 1;
        num2[tmp2] = 1;
    }
    cout << tot << endl;
    return 0;
}