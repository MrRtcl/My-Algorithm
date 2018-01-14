#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node{
    int key,cnt,size;
    node *l,*r,*pre;
    node(){
        l = NULL;
        r = NULL;
        pre = NULL;
        key = 0;
        cnt = 0;
        size = 0;
    }
}*s,*tmp;
int ans = 0;

inline void update(node *&p){
    if(p){
        p->size = p->cnt;
        if(p->l)    p->size += p->l->size;
        if(p->r)    p->size += p->r->size;
    }
}

inline void rrotate(node *&x){
    node *y = x->pre;
    y ->l = x->r;
    if(x->r){
        x->r->pre = y;
    }
    x->pre = y->pre;
    if(y->pre){
        if(y->pre->l == y){
            y->pre->l = x;
        }else{
            y->pre->r = x;
        }
    }
    x->r = y;
    y->pre = x;
    if(y == s)
        s = x;
    update(y);
    update(x);
}

inline void lrotate(node *&x){
    node *y = x->pre;
    y->r = x->l;
    if(x->l){
        x->l->pre = y;
    }
    x->pre = y->pre;
    if(y->pre){
        if(y->pre->l == y){
            y->pre->l = x;
        }else{
            y->pre->r = x;
        }
    }
    x->l = y;
    y->pre = x;
    if(y == s)
        s = x;
    update(y);
    update(x);
}

inline void splay(node *&x,node *&root){
    node *p;
    while(x->pre){
        p = x->pre;
        if(!p->pre){
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
    root = x;
}

inline node *bst_insert(int key,node *&p,node *pre){
    if(p == NULL){
        p = new node;
        p->pre = pre;
        p->l = NULL;
        p->r = NULL;
        p->key = key;
        p->cnt = 1;
        p->size = 1;
        update(p->pre);
        tmp = p;
        return p;
    }
    if(p->key == key){
        p->cnt++;
        update(p->pre);
        update(p);
        return p; 
    }
    if(key > p->key){
        p->r = bst_insert(key,p->r,p);
    }else{
        p->l = bst_insert(key,p->l,p);
    }
    return p;
}

inline node *bst_find(int key,node *p){
    if(!p){
        return NULL;
    }
    if(key == p->key){
        ++ans;
        return p;
    }
    if(key > p->key){
        ans += ((p->l)?p->l->size:0) + p->cnt;
        return bst_find(key,p->r);
    }else{
        return bst_find(key,p->l);
    }
}

inline node *find(int key){
    ans = 0;
    node *p = bst_find(key,s);
    if(p == NULL){
        return NULL;
    }else{
        splay(p,s);
        return p;
    }
}

inline node *insert(int key){
    tmp = NULL;
    node *p = bst_insert(key,s,NULL);
    if(tmp == NULL){
        return NULL;
    }else{
        splay(tmp,s);
        return tmp;
    }
}

inline node *getmin(node *&root){
    node *p = root;
    while(p->l){
        p = p->l;
    }
    splay(p,root);
    return p;
}

inline node *getmax(node *&root){
    node *p = root;
    while(p->r){
        p = p->r;
    }
    splay(p,root);
    return p;
}

inline node *getpre(int key){
    node *p = find(key);
    if(p){
        p = p->l;
        if(!p)
            return NULL;
        p = getmax(p);
    }
    return p;
}

inline node *getnext(int key){
    node *p = find(key);
    if(p){
        p = p->r;
        if(!p)
            return NULL;
        p = getmin(p);
    }
    return p;
}

inline node *join(node *&x,node *&y){
    if(!x){
        if(!y){
            return NULL;
        }
        y->pre = NULL;
        return y;
    }
    if(!y){
        if(!x){
            return NULL;
        }
        x->pre = NULL;
        return x;
    }
    x = getmax(x);
    x->pre = NULL;
    x->r = y;
    y->pre = x;
    return x;
}

inline bool del(int key){
    node *p = find(key);
    if(p->cnt > 1){
        p->cnt--;
        p->size--;
        update(p->pre);
        return true;
    }
    if(p){
        s = join(p->l,p->r);
        update(s);
        free(p);
        return true;
    }else{
        return false;
    }
}

inline node *findx(int k){
    node *p = s;
    while(1){
        if(p->l && (k <= p->l->size)){
            p = p->l;
        }else{
            int tmp = ((p->r)?p->r->size:0) + p->cnt;
            if(k <= tmp){
                splay(p,s);
                return p;
            }
            k -= tmp;
            p = p->r; 
        }
    }
}

inline void LMR(node *p){
    if(p){
        LMR(p->l);
        for(int i = 1;i <= p->cnt;i++)
            cout << p->key << " ";
        LMR(p->r);
    }
}

int main(){
    int n,cmd,num;
    scanf("%d",&n);
    for(register int i = 1;i <= n;i++){
        scanf("%d",&cmd);
        switch(cmd){
            case 1:{
                scanf("%d",&num);
                insert(num);
                break;
            }
            case 2:{
                scanf("%d",&num);
                del(num);
                break;
            }
            case 3:{
                scanf("%d",&num);
                find(num);
                printf("%d\n",ans);
                break;
            }
            case 4:{
                scanf("%d",&num);
                node *p = findx(num);
                printf("%d\n",p->key);
                break;
            }
            case 5:{
                scanf("%d",&num);
                insert(num);
                node *p = getpre(num);
                del(num);
                printf("%d\n",p->key);
                break;
            }
            case 6:{
                scanf("%d",&num);
                insert(num);
                node *p = getnext(num);
                del(num);
                printf("%d\n",p->key);
                break;
            }
        }
    }
    getchar();
    getchar();
    return 0;
}