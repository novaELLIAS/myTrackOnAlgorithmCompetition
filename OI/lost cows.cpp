#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[8010];
int res[8010];
bool ex[8010];
int tree[8010];
inline int lowbit(int x){return x&(-x);}
void update(int x,int k){while(x<=n)tree[x]+=k,x+=lowbit(x);}
int query(int x){int ress=0;while(x!=0)ress+=tree[x],x-=lowbit(x);return ress;}
bool check(int x,int k)
{
	if(query(x)>k)return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	for(int i=n;i>=1;--i)
	{
		int l=1,r=n,ans=1;
		while(l<=r)
		{
		    int mid=(l+r)>>1;
		    if(check(mid,a[i]))l=mid+1,ans=mid;
		    else r=mid-1;
		}
		update(ans,1);
		ex[ans]=1;
		res[i]=ans;
	}
	for(int i=1;i<=n;++i)printf("%d ",res[i]);
}
