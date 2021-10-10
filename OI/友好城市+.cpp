#include<algorithm>
#include<stdio.h>
using namespace std;

#define max(x,y) x>y? x:y
#define maxn 200005

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
inline void fastwrite(int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwriteline(int x)
{
	fastwrite(x);
	putchar('\n');
}

int n, ans;
struct node
{
	int ori,fri;
} s[maxn];
int nico[maxn], dp[maxn];

void INPUT()
{
	n = fastread();
	int x, y, tem = 1;
	for(int i = 1; i <= n; i++)
	{
		x = fastread();
		y = fastread();
		s[tem].ori=x;
		s[tem].fri=y;
		tem++;
	}
}
bool cmp(node a,node b)
{
	return a.ori<b.ori;
}
void WORK()
{
	int top = 0;
	/*
	for(int i=1; i<=n; i++) ans[i]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i-1; j++)
		{
			if(work[i]>work[j])
			{
				ans[i]=ans[i]>ans[j]+1? ans[i]:ans[j]+1;
			}
			tot=ans[i]>tot? ans[i]:tot;
		}
	}
	*/
	for(int i = 1; i <= n; i++)
    {
        if(s[i].fri >= nico[top]) nico[++ top] = s[i].fri;
		else nico[lower_bound(nico,nico+top,s[i].fri)-nico] = s[i].fri;
    }
	
	fastwrite(top);
}
int main(void)
{
	INPUT();
	sort(s+1,s+n+1,cmp);
	WORK();
}
