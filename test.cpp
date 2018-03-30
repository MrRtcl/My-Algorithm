#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    string name;
    int num;
    cout << "input the name of food:";
    cin >> name;
    cout << "\ninput the number of food:";
    cin >> num;
    freopen("out.txt","w",stdout);
    for(int i = 1;i <= num;i++){
        cout << name << endl;
    }
    return 0;
}