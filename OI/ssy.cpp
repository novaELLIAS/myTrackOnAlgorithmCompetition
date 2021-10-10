#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

const int mod = 1234567891;
const int inf = (1<<29);
const int N = 31;
int a[N],now[N],vis[N];
int n,m,ans;

static void dfs(int x,int s) {
	int tmp=now[s];
	now[s]=a[x];
	if(s==n)
	{
		for(int i=2; i<=n; ++i) if(abs(now[i]-now[i-1])%m==0) return;
		now[s] = tmp;
		ans++, ans%=mod;
		return;
	}
	vis[x]=true;
	for(int i=1; i<=n; ++i) if(!vis[i]) dfs(i,s+1);
	vis[x]=0;
	now[s]=tmp;
}

int main()
{
	freopen ("ssy.in", "r", stdin);
	freopen ("ssy.out","w",stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	for(int i = 0; i <= n; ++ i) now[i] = inf;
	scanf("%d",&m);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}
