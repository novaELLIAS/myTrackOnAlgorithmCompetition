#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "queue"

#define maxn 100001
#define rint register int
#define ll long long

using namespace std;

inline int read()
{
	int x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

int n, m, k;
struct node {
	int y, z;
	node *next;
} *head[maxn];
queue <int> que;
int dis[maxn], vis[maxn];
bool inq[maxn];

inline void add (int x, int y, int z)
{
	node *link = new node;
	link -> y = y;
	link -> z = z;
	link -> next = head[x];
	head[x] = link;
}

inline bool spfa ()
{
	memset (vis, 0, sizeof vis);
	memset (inq, 0, sizeof inq);
	int f;
	while (!que.empty ())
	{
		f = que.front ();
		que.pop ();
		inq[f] = false;
		for (node *link = head[f]; link; link = link -> next)
		{
			if (dis[link -> y] < dis[f] + link->z)
			{
				dis[link->y] = dis[f] + link->z;
				if (++ vis[link->y] >= n) return false;
				if (!inq[link->y])
				{
					inq[link->y] = true;
					que.push (link->y);
				}
			}
		}
	}
	return true;
}
int main ()
{
	n = read (), m = read ();
	int op, x, y;
	while (m --)
	{
		op = read (), x = read (), y = read ();
		if (op == 1)
		{
			add (x, y, 0);
			add (y, x, 0);
		} else if (op == 2) {
			if (x == y)
			{
				puts ("-1");
				exit (0);
			} else add (x, y, 1);
		} else if (op == 3) add (y, x, 0);
		else if (op == 4) {
			if (x == y)
			{
				puts ("-1");
				exit (0);
			} else add (y, x, 1);
		}else add (x, y, 0);
	}
	
	for (rint i = 1; i <= n; i ++)
	{
		dis[i] = 1;
		que.push (i);
	}
	if (!spfa ())
	{
		puts ("-1");
		exit (0);
	} else {
		ll ans = 0;
		for (rint i = 1; i <= n; i ++)
		{
			ans += dis[i];
		}
		printf ("%I64d", ans);
		return 0;
	}
	return 0;
}
