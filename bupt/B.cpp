#include <iostream>
#include <cstdio>
#define MAX 1000005
using namespace std;
int arr[MAX],n;

int main(){
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int tmp;
        scanf("%d",&tmp);
        arr[tmp]++;
    }
    for(int i = 1;i <= 1000001;i++){
        if(arr[i] > n/2){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}