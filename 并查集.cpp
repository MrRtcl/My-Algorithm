#include <iostream>
using namespace std;
int m,n,f[10050],arr[10050];

int search(int x){
	return x == f[x] ? x : f[x] = search(f[x]);
}

void zip(int a,int b){
    int fa = search(a);
    int fb = search(b);
    if(fa != fb){
        f[fa] = fb;
    }
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        f[i] = i;
    }
    while(m--){
        int com;
        cin >> com;
        switch(com){
            case 1:{
                int x,y;
                cin >> x >> y;
                zip(x,y);
                break;
            }
            case 2:{
                int x,y,fa,fb;
                cin >> x >> y;
                fa = search(x);
                fb = search(y);
                if(fa == fb){
                    cout << 'Y' << endl;
                }else{
                    cout << 'N' << endl;
                }
                break;
            }
        }
    }
    return 0;
}