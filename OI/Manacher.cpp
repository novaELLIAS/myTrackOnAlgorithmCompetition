#include<cstdio>
#include<algorithm>
#define MAXN 1000005
using namespace std;
int n,r[MAXN],pt;
int pos,MaxRight;
char t[MAXN],s[MAXN];
int main()
{
	scanf("%d%s",&n,t+1);
	for (int i=1;i<=n;i++)
	{
		s[i*2-1]='#';
		s[i*2]=t[i];
	}
	s[n*2+1]='#';
	for (int i=1;i<=n*2+1;i++)
	{
		if (i>MaxRight)r[i]=1;
		else r[i]=min(r[pos*2-i],MaxRight-i+1);
		pt=i+r[i];
		while (pt<=n*2+1&&i*2-pt>=1&&s[pt]==s[i*2-pt])
		{
			if (pt>MaxRight)
			{
				MaxRight=pt;
				pos=i;
			}
			pt++;r[i]++;
		}
	}
	for (int i=1;i<=n*2+1;i++)
		printf("%c ",s[i]);
	printf("\n");
	for (int i=1;i<=n*2+1;i++)
		printf("%d ",r[i]);
	return 0;
}
