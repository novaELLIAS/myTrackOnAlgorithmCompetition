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

// ���µ�ǰroot�ڵ�
void update(int root)
{
	node[root]=node[root<<1]+node[root<<1|1];
}

// ����data[]�����߶��� 
void build(int root, int l, int r)
{
	if (l==r) { // Ҷ�ڵ�
		node[root] = data[l]; 
	} else { // ��Ҷ�ڵ� 
		int mid=(l+r)/2; // [l, r] -> [l, mid],[mid+1, r]
		build(LSON); // build(root<<1,l,mid);
		build(RSON);
		update(root);
	}
}

// ����k������x 
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

// ѯ��[L, R]��[l, r]�������ֵĺ� 
int query(int L, int R, int root, int l, int r)
{
	if (L <= l && r <= R) { // ����ȫ����
		return node[root]; 
	} else {
		int mid=(l+r)/2;
		int ans=0;
		if (L<=mid) ans += query(L, R, LSON); // ��������н��� 
		if (R>mid) ans += query(L, R, RSON); // ���Ҷ����н��� 
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

