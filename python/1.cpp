#include <iostream>
using namespace std;

int main(){
    int x = 0x42;
    int s = ((16 * x)|(x>>4))%256;
    cout << s;
    return 0;
}