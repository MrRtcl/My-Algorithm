#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 100020
using namespace std;
int tot,n;

struct node{
    int key,size,cnt;
    node *l,*r,*pre;
};
node *root;

inline void update(node *&p){
    if(p){
        p->size = p->cnt;
        if(p->l)    p->size += p->l->size;
        if(p->r)    p->size += p->r->size;
    }
}

node* bst_insert(node *&p,int key,node *pre){
    if(!p){
        p = new node;
        p->key = key;
        p->l = NULL;
        p->r = NULL;
        p->pre = pre;
        p->size = 1;
        p->cnt = 1;
        update(p->pre);
        return p;
    }
    if(key == p->key){
    	p->cnt++;
    	update(p);
    	update(p->pre);
    }else if(key > p->key){
        return bst_insert(p->r,key,p);
    }
    else{
        return bst_insert(p->l,key,p);
    }
    return p;
}

node* bst_search(node *p,int key){
    if(!p)
        return NULL;
    if(p->key == key)
        return p;
    if(key > p->key)
        return bst_search(p->r,key);
    if(key < p->key)
        return bst_search(p->l,key);
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
    update(y);
    update(x);
}

inline void splay(node *&x,node *&to){
    node *s = to->pre;
    node* p;
    while(x->pre != s){
        p = x->pre;
        if(p->pre == s){
            if(p->l == x){
                rrotate(x);
            }else{
                lrotate(x);
            }
        }else if(x == p->l){
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
void insert(int key){
    node *p = bst_insert(root,key,NULL);
    splay(p,root);
}

node* search(int key){
    node *p = bst_search(root,key);
    if(p){
        splay(p,root);
    }
    return p;
}

node* getmax(node *p){
    while(p->r){
        p = p->r;
    }
    return p;
}

node* getmin(node *p){
    while(p->l){
        p = p->l;
    }
    return p;
}

int getpre(int key){
    search(key);
    node *t = getmax(root->l);
    splay(t,root);
    return t->key;
}

int getnext(int key){
    search(key);
    node *t = getmin(root->r);
    splay(t,root);
    return t->key;
}

int getrank(int key){
	node *p = search(key);
    return (p->l?p->l->size:0)+1;
}

inline node *findx(node *p,int k){
	int cnt = p->l?p->l->size:0;
    if(k <= cnt){
    	return findx(p->l,k);
    }else if(k > cnt+p->cnt){
    	return findx(p->r,k-cnt-(p->cnt));
    }
    return p;
}

void pop(int key){
    node *p = bst_search(root,key);
    if(p){
        splay(p,root);
        if(p->cnt > 1){
            p->cnt--;
            p->size--;
            update(p->pre);
            return;	
        }
        if(!p->l){
            root = p->r;
            if(root == NULL){
            	return;
            }
        }else{
            node* t = getmax(p->l);
            splay(t,root->l);
            t->r = root->r;
            t->pre = NULL;
            if(root->r){
            	root->r->pre = t;
            }
            root = t;
            update(root);
        }
    }
}

int main(){
    int n;
//    freopen("1.txt","w",stdout);
    scanf("%d",&n);
    while(n--){
        int cmd,num;
        scanf("%d %d",&cmd,&num);
        if(cmd == 1){
            insert(num);
        }else if(cmd == 2){
            pop(num);
        }else if(cmd == 3){
            printf("%d\n",getrank(num));
        }else if(cmd == 4){
            node *p = findx(root,num);
            splay(p,root);
            printf("%d\n",root->key);
        }else if(cmd == 5){
            insert(num);
            getpre(num);
            printf("%d\n",root->key);
            pop(num);
        }else if(cmd == 6){
            insert(num);
            getnext(num);
            printf("%d\n",root->key);
            pop(num);
        }
 	}
    return 0;
}
