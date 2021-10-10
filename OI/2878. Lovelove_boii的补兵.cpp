#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>
#include <queue>

using namespace std;

#define maxn 1001
#define rint register int

inline int read ()
{
	int x = 0;char c = getchar();bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, _, ans, sum, fro;
priority_queue <int , vector <int>, greater <int> > que;

int main ()
{
	//freopen ("bb.in","r",stdin);
	//freopen ("bb.out","w",stdout);
	_ = read ();
	for (rint j = 1; j <= _; j ++)
	{
		while (!que.empty ()) que.pop();
		ans = sum = 0;
		n = read ();
		for (rint i = 1; i <= n; i ++)
		{
			fro = read ();
			que.push(fro);
		}
		while (!que.empty())
		{
			while (!que.empty() && !(que.top()-sum)) que.pop();
			fro = que.top(); que.pop();
			if (fro - sum == 1) ans ++;
			else que.push(fro - 1);
			sum ++;
		}
		
		printf ("Case #%d: %d\n", j, ans);
	}
	return 0;
}
