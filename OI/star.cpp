#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
struct point
{
	int x,y;
}p[35010];
int ans[35010];
bool cmp1(point a,point b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
int s[35010];
inline int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int k)
{
	while(x<=35000)
	{
		s[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)
{
	int res=0;
	while(x!=0)
	{
		res+=s[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,cmp1);
	for(int i=1;i<=n;++i)
	{
		ans[query(p[i].y+1)]++;
		update(p[i].y+1,1);
	}
	for(int i=0;i<n;++i)printf("%d\n",ans[i]);
}
