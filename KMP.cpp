#include<cstdio>
#define MAXN 1000005
using namespace std;
int n,pt,next[MAXN];
char str[MAXN];
int main()
{
	scanf("%d%s",&n,str+1);
	next[0]=-1;
	for (int i=2;i<=n;i++)
	{
		pt=next[i-1];
		while (pt!=-1&&str[i]!=str[pt+1])
			pt=next[pt];
		if (pt==-1)continue;
		next[i]=pt+1;
	}
	for (int i=1;i<=n;i++)
		printf("%d ",next[i]);
	return 0;
}
