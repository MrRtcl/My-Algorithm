#include <iostream>
#include <cstring>
#define MAX 10000050
using namespace std;
bool prime[MAX];
int primes[MAX],m,n,cnt;

void make_prime(){
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = 0;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            primes[++cnt] = i;
        }
        for(int j=1;j <= cnt && i * primes[j] <= MAX;j++){
            prime[i * primes[j]] = 0;
            if(!(i%primes[j]))
                break;
        }
    }
}

int main(){
    cin >> n >> m;
    make_prime();
    while(m--){
        int a;
        cin >> a;
        if(prime[a]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}