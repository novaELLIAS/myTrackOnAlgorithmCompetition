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

#define maxn 16010
#define nico edge[pos]
struct node {
	int v, u;
};
int n, ans;
vector <node> edge[maxn];
//vector <node> son[maxn];
//bool father[maxn];
bool visit[maxn];
int /*dp[maxn][2], */beauty[maxn];

int DFS(int pos)
{
	int x;
	//if(!visit[nico[i].u])
	//{
		//visit[nico[i].u] = true;
		for(int i = 0; i < nico.size(); i ++)
		{
			if(!visit[nico[i].u])
			{
				visit[nico[i].u] = true;
				x = DFS((int) nico[i].u);
				if(x > 0) beauty[pos] += x;
				ans = max(beauty[pos], ans);
			}
		}
	//}
	return beauty[pos];
}
int main()
{
	n = fastread();
	for(int i = 1; i <= n; i ++) beauty[i] = fastread();
	for(int i = 1; i <= n-1; i ++)
	{
		int vv = fastread();
		int uu = fastread();
		edge[vv].push_back((node) {vv, uu});
		edge[uu].push_back((node) {uu, vv});
	}
	visit[1] = true;
	DFS(1);
	printf("%d", ans);
}
