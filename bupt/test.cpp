#include <iostream>
using namespace std;

int k,x;

int main(){
    cin >> k;
    for(int i = 1;i <= k;i++){
        if(i*i+i-2*k >= 0){
            cout << i-1 << "\t" << i << endl;
            break;
        }
    }
    return 0;
}

//1 3 6 10