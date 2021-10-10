#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 500000 + 100;

#define ROOT 1,1,n
#define LSON root<<1,l,mid
#define RSON root<<1|1,mid+1,r

int n, m;
int data[MAXN];

// SegTree
int node[MAXN<<2];

// 更新当前root节点
void update(int root)
{
	node[root]=node[root<<1]+node[root<<1|1];
}

// 根据data[]创建线段树 
void build(int root, int l, int r)
{
	if (l==r) { // 叶节点
		node[root] = data[l]; 
	} else { // 非叶节点 
		int mid=(l+r)/2; // [l, r] -> [l, mid],[mid+1, r]
		build(LSON); // build(root<<1,l,mid);
		build(RSON);
		update(root);
	}
}

// 将第k个数加x 
void change(int k, int x, int root, int l, int r)
{
	if (l==r) {
		node[root]+=x;
	} else {
		int mid=(l+r)/2;
		if (k<=mid) change(k, x, LSON);
		else change(k, x, RSON);
		update(root);
	}
}

// 询问[L, R]与[l, r]交集部分的和 
int query(int L, int R, int root, int l, int r)
{
	if (L <= l && r <= R) { // 被完全包含
		return node[root]; 
	} else {
		int mid=(l+r)/2;
		int ans=0;
		if (L<=mid) ans += query(L, R, LSON); // 和左儿子有交集 
		if (R>mid) ans += query(L, R, RSON); // 和右儿子有交集 
		return ans;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%d", &data[i]);
	
	build(ROOT); // build(1,1,n);
	
	while(m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a==1) change(b, c, ROOT);
		else printf("%d\n", query(b, c, ROOT));
	}
	
	return 0;
}

