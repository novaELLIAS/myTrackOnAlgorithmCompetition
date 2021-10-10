#include <bits/stdc++.h>
using namespace std;

const int maxm = 100000 + 10;
const int maxn = 20000 + 10;
int m,n;
struct node{
	int a, b;
	int point;
}s[maxm];
bool enemy[maxn], father[maxn];

void INPUT(int times)
{
	for(int i = 1; i <= times; i++)
	{
		scanf("%d %d %d", &s[i].a, &s[i].b, s[i].point);
	}
}
bool cmp(node x, node y)
{
	return x.point > y.point;
}
int find(int x)
{
	if(x == father[x]) return x;
	father[x] = find(father[x]);
	return father[x];
}
void unionn(int x, int y)
{
	x = find(father[x]);
	y = find(father[y]);
	father[x] = y;
}
void judge(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return true;
	else return false;
}
void WORK()
{
	for(int i = 1; i <= m; i++)
	{
		if(check())
	}
}
int main()
{
	scanf("%d %d",&n, &m);
	INPUT(m);
	sort(s+1, s+m+1, cmp);
	WORK();
}
