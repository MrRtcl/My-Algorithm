#include <iostream>
#define MAX 10050
using namespace std;
int sum[MAX<<2],add[MAX<<2],arr[MAX];
int m,n;

void pushup(int rt){
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
}

void pushdown(int rt,int ln,int rn){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] +=  add[rt]*ln;
        sum[rt<<1|1] += add[rt]*rn;
        add[rt] = 0;
    }
}

void build(int l,int r,int rt){
    if(l == r){
        sum[rt] = arr[l];
        return;
    }
    int m = (l+r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(L <= l && r <= R){
        return sum[rt];
    }
    int m = (l+r) >> 1;
    pushdown(rt,m-l+1,r-m);
    int ans = 0;
    if(L <= m) ans += query(L,R,l,m,rt<<1);
    if(R > m) ans += query(L,R,m+1,r,rt<<1|1);
    return ans; 
}

void update(int L,int R,int C,int l,int r,int rt){
    if(L <= l && r <= R){
        sum[rt] += C*(r-l+1);
        add[rt] += C;
        return ;
    }
    int m = (l+r) >> 1;
    pushdown(rt,l-m+1,r-m);
    if(L <= m) update(L,R,C,l,m,rt<<1);
    if(R > m) update(L,R,C,m+1,r,rt<<1|1);
    pushup(rt);
}

int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    build(1,n,1);
    while(m--){
        char com;
        cin >> com;
        switch(com){
            case 'Q':{
                int a,b;
                cin >> a >> b;
                cout << query(a,b,1,n,1) << endl;
                break;
            }
            case 'A':{
                int a,b,c;
                cin >> a >> b >> c;
                update(a,b,c,1,n,1);
                break;
            }
        }
    }
    return 0;
}