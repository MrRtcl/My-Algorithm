#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#define MAX 500050
using namespace std;
int n,h;
struct Point{
	int x,y;
	Point(){
		x = 0;
		y = 0;
	}
	Point(int a,int b){
		x = a,y = b;
	}
}arr[MAX];

Point stack[MAX];

int multiply(Point p1,Point p2,Point p3){
	int x1 = p2.x-p1.x;
	int x2 = p3.x-p1.x;
	int y1 = p2.y-p1.y;
	int y2 = p3.y-p1.y;
	return (x1*y2)-(x2*y1);
}

int dis(Point x,Point y){
	return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}

int cmp(Point a,Point b){
	int num = multiply(arr[1],a,b);
	if(num == 0){
		return a.x < b.x;
	}
	return num > 0;
}

void tubao(){
	int k = 1;
	Point p = arr[1];
	for(int i = 2;i <= n;i++){
		if(arr[i].y < p.y || (arr[i].y == p.y && arr[i].x < p.x)){
			k = i;
			p = arr[i];
		}
	}
	swap(arr[k],arr[1]);
	sort(arr+2,arr+1+n,cmp);
	stack[++h] = arr[1];
	stack[++h] = arr[2];
	stack[++h] = arr[3];
	for(int i = 4;i <= n;i++){
		while(multiply(stack[h-1],stack[h],arr[i]) < 0){
			h--;
		}
		stack[++h] = arr[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %d",&arr[i].x,&arr[i].y);
	}
	tubao();
	long long int maxx = -1;
	for(int i = 1;i <= h;i++){
		for(int j = i+1;j <= h;j++){
			long long int num = dis(stack[i],stack[j]);
			maxx = max(maxx,num);
		}
	}
	printf("%lld ",maxx);
	return 0;
}
