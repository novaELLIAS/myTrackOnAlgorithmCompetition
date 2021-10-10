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

// ���µ�ǰroot�ڵ� 
void update(int root, int l, int r)
{
	node[root].sum=node[root<<1].sum+node[root<<1|1].sum+node[root].flag*(r-l+1);
}

// ����data[]�����߶��� 
void build(int root, int l, int r)
{
	if (l==r) { // Ҷ�ڵ�
		node[root].sum = data[l]; 
	} else { // ��Ҷ�ڵ� 
		int mid=(l+r)/2; // [l, r] -> [l, mid],[mid+1, r]
		build(LSON); // build(root<<1,l,mid);
		build(RSON);
		update(root, l, r);
	}
}

// ����L����R������x 
void change(int L, int R, int x, int root, int l, int r)
{
	if (L<=l && r<=R) { // ��ȫ���� 
		node[root].flag += x;
		node[root].sum += x * (r - l + 1);
	} else {
		int mid=(l+r)/2;
		if (L<=mid) change(L, R, x, LSON);
		if (R>mid) change(L, R, x, RSON);
		update(root, l, r);
	}
}

// ѯ��[L, R]��[l, r]�������ֵĺ� 
int query(int L, int R, int root, int l, int r)
{
	if (L <= l && r <= R) { // ����ȫ����
		return node[root].sum; 
	} else {
		int mid=(l+r)/2;
		int ans=0;
		if (L<=mid) ans += query(L, R, LSON); // ��������н��� 
		if (R>mid) ans += query(L, R, RSON); // ���Ҷ����н��� 
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

