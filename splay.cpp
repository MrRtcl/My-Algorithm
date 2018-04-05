#include <iostrem>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define MAX 1000
using namespace std;

struct node{
    int key,size,cnt;
    node *l,*r,*pre;
}*root;

void update(node *rt){
    rt->size = rt->l?rt->l->size:0 + rt->r?rt->r->size:0 + rt->cnt; 
}

void lrotate(node *&x){
    node *y = x->pre;
    y->r = x->l;
    if(x->l){
        x->l->pre = y;
    }
    x->pre = y->pre;
    if(y->pre){
        if(y == y->pre->l){
            y->pre->l = x;
        }else{
            y->pre->r = x;
        }
    }
    x->l = y;
    y->pre = x;
    update(y);
    update(x);
}

void rrotate(node *&x){
    node *y = x->pre;
    y->l = x->r;
    if(x->r){
        x->r->pre = y;
    }
    x->pre = y->pre;
    if(y->pre){
        if(y == y->pre->l){
            y->pre->l = x;
        }else{
            y->pre->r = x;
        }
    }
    x->r = y;
    y->pre = x;
    update(y);
    update(x);
}

void splay(node *&x,node *&to){
    node *s = to->pre;
    node *p;
    while(x->pre != s){
        p = x->pre;
        if(p->pre == s){
            if(p->l == x){
                rrotate(x);
            }else{
                lrotate(x);
            }
            break;
        }
        if(x == p->l){
            if(p == p->pre->l){
                rrotate(p);
                rrotate(x);
            }else{
                rrotate(x);
                lrotate(x);
            }
        }else{
            if(p == p->pre->r){
                lrotate(p);
                lrotate(x);
            }else{
                lrotate(x);
                rrotate(x);
            }
        }
    }
    to = x;
}

nod 

int main(){
    return 0;
}