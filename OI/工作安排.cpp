#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
typedef long long ll;

struct node {
	int t,v;
} a[100001];
ll ans;
int heap[100001],n,dir;

bool cmp(node x,node y) {
	return x.t<y.t;
}
void push(node x) {
	ans+=x.v;
	heap[++dir]=x.v;
	int now=dir;
	while(now>1 and heap[now/2]>heap[now]) {
		swap(heap[now],heap[now/2]);
		now/=2;
	}
}
void pop() {
	ans-=heap[1];
	heap[1]=heap[dir--];
	int x=1;
	while (x<=(dir/2)) {
		int next=x*2;
		if (next<dir and heap[next|1]<heap[next]) next++;
		if (heap[next]>heap[x]) return;
		swap(heap[next],heap[x]);
		x=next;
	}
}
int main(void) {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d%d",&a[i].t,&a[i].v);
	sort(a+1,a+1+n,cmp);
	int tim=0;
	for(int i=1; i<=n; i++) {
		push(a[i]);
		tim++;
		if(tim>a[i].t) {
			pop();
			tim--;
		}
	}

	printf("%lld\n",ans);
}
