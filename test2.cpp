#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <algorithm>

#define maxn 500001
#define lowbit(x) (x&(-x))

int c[maxn];

struct Node {
	int v,index;
	bool operator < (const Node &b) const {
		return v<b.v;
	}
} node[maxn];

void __fastcall add (int i, int n)
{
	while (i<n) ++ c[i], i+=lowbit(i);
}
long long __fastcall sum (int i)
{
	register long long res=0ll;
	while(i>0) res+=c[i], i-=lowbit(i);
	return res;
}
 
signed main ()
{
	register int n, a;
	scanf ("%d", &n); ++ n;
	for (register int i=1; i^n;++ i) {
		scanf("%d", &a);
		node[i].index=i, node[i].v=a;
	}
	std::sort (node+1, node+n);
	register long long ans=0ll;
	for (register int i=1; i^n; ++ i) {
		add(node[i].index, n);
		ans += i-sum(node[i].index);
	}
	return printf ("ans= %lld\n", ans), 0;
}
