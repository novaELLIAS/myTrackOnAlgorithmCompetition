#include <stdio.h>
#include <vector>
using namespace std;

#define max(x,y) x>y? x:y
#define min(x,y) x<y? x:y

inline int fastread()
{
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		n = n*10 + c-'0';
		c = getchar();
	}
	return sign*n;
}

#define maxn 6010
int n, root;
vector <int> son[maxn];
bool father[maxn];
int dp[maxn][2], happy[maxn];

void solve(int bt)
{
	dp[bt][0] = 0;
	dp[bt][1] = happy[bt];
	for(int i = 0; i< son[bt].size(); i++)
	{
		int k = son[bt][i];
		solve(k);
		dp[bt][0] += max(dp[k][0], dp[k][1]);
		dp[bt][1] += dp[k][0];
	}
}
int main(void)
{
	n = fastread();
	for(int i = 1; i <= n; i++) happy[i] = fastread();
	for(int i = 1; i <= n-1; i++)
	{
		int k = fastread();
		int l = fastread();
		son[l].push_back(k);
		father[k] = true;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(!father[i]){
			root = i;
			break;
		}
	}
	solve(root);
	printf("%d", max(dp[root][1], dp[root][0]));
}
