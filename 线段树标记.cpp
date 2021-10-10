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
struct Node
{
	int sum, flag;
};
Node node[MAXN<<2];

// 更新当前root节点 
void update(int root, int l, int r)
{
	node[root].sum=node[root<<1].sum+node[root<<1|1].sum+node[root].flag*(r-l+1);
}

// 根据data[]创建线段树 
void build(int root, int l, int r)
{
	if (l==r) { // 叶节点
		node[root].sum = data[l]; 
	} else { // 非叶节点 
		int mid=(l+r)/2; // [l, r] -> [l, mid],[mid+1, r]
		build(LSON); // build(root<<1,l,mid);
		build(RSON);
		update(root, l, r);
	}
}

// 将第L到第R个数加x 
void change(int L, int R, int x, int root, int l, int r)
{
	if (L<=l && r<=R) { // 完全包含 
		node[root].flag += x;
		node[root].sum += x * (r - l + 1);
	} else {
		int mid=(l+r)/2;
		if (L<=mid) change(L, R, x, LSON);
		if (R>mid) change(L, R, x, RSON);
		update(root, l, r);
	}
}

// 询问[L, R]与[l, r]交集部分的和 
int query(int L, int R, int root, int l, int r)
{
	if (L <= l && r <= R) { // 被完全包含
		return node[root].sum; 
	} else {
		int mid=(l+r)/2;
		int ans=0;
		if (L<=mid) ans += query(L, R, LSON); // 和左儿子有交集 
		if (R>mid) ans += query(L, R, RSON); // 和右儿子有交集 
		ans += node[root].flag * (min(r, R) - max(L, l) + 1);
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
		int type;
		scanf("%d", &type);
		if(type==1) {
			int L, R, x;
			scanf("%d%d%d", &L, &R, &x);
			change(L, R, x, ROOT);
		} else {
			int L, R;
			scanf("%d%d", &L, &R);
			printf("%d\n", query(L, R, ROOT));
		}
	}
	
	return 0;
}

