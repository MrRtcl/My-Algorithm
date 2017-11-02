#include <iostream>
#include <cstring>
using namespace std;
int n,m,e,ans;
bool isused[3006];
int match[3006];

struct node{
    int to;
    node *next;
}*head[3007];

void addedge(int a,int b){
    node *t = new node;
    t->next = head[a];
    t->to = b;
    head[a] = t;
}

int read(){
    int x=0,w=1;
    char chr = 0;
    while(chr < '0' || chr > '9'){
        if(chr == '-')
            w = -1;
        chr = getchar();
    }
    while(chr >= '0' && chr <='9'){
        x = (x << 3) + (x << 1) + chr - '0';
        chr = getchar();
    }
    return x*w;
}

bool find(int x){
    for(register node *t = head[x];t;t=t->next){
        if(!isused[t->to]){
            isused[t->to] = 1;
            if(match[t->to] == 0 || find(match[t->to])){
                match[t->to] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    n = read();
    m = read();
    e = read();
    for(register int i=1;i<=e;i++){
        int a,b;
        a = read();
        b = read();
        if(a > n) continue;
        if(b > m) continue;
        addedge(a,b);
    }
    for(register int i=1;i<=n;i++){
        memset(isused,0,sizeof(isused));
        if(find(i)) ans++;
    }
    cout << ans << endl; 
    return 0;
}