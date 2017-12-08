#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node{
    int key;
    node *l,*r,*pre;
}*root;

bool insert(node *&p,int key,node *pre){
    if(!p){
        p = new node;
        p->key = key;
        p->l = NULL;
        p->r = NULL;
        p->pre = pre;
        return true;
    }
    if(key >= p->key){
        return insert(p->r,key,p);
    }
    else{
        return insert(p->l,key,p);
    }
    return false;
}

node* search(node *p,int key){
    if(!p)
        return p;
    if(p->key == key)
        return p;
    if(key > p->key)
        return search(p->r,key);
    if(key < p->key)
        return search(p->l,key);
}

bool del(int key){
    node *p = search(root,key);
    if(!p)
        return false;
    if(!p->l && !p->r){
        if(!p->pre){
            free(p);
            root = NULL;
            return true;
        }
        if(p->pre->l == p){
            p->pre->l = NULL;
        }
        if(p->pre->r == p){
            p->pre->r = NULL;
        }
        free(p);
        return true;
    }
    if(p->l && !p->r){
        p->key = p->l->key;
        free(p->l);
        p->l = NULL;
        return true;
    }
    if(p->r && !p->l){
        p->key = p->r->key;
        free(p->r);
        p->r = NULL;
        return true;
    }
    if(p->r && p->l){
        node *t = p->r;
        while(t->l){
            t = t->l;
        }
        p->key = t->key;
        if(t->r){
            t->r->pre = t->pre;
            t->pre->l = t->r;
            free(t);
            return true;
        }else{
            t->pre->l = NULL;
            free(t);
            return true;
        }
    }
}

int main(){

    return 0;
}