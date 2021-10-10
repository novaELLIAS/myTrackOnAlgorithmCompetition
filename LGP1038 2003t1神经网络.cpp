#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include <queue>

using namespace std;

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

inline void add (int, int, int);

#define maxn 201

struct node {
	int dataspace;
	int val;
	int next;
} data[maxn];
struct OUT {
	int dataspace;
	friend bool operator < (OUT a, OUT b)
	{
		return a.dataspace > b.dataspace;
	}
};
priority_queue <OUT> output;
queue <int> nico;
int n, m, cnt, fro, t;
int c[maxn], u[maxn], in[maxn], out[maxn], ss[maxn], head[maxn]; 
bool flag, visit[maxn];

int main ()
{
	n = fastread ();
	m = fastread ();
	for (int i = 1; i <= n; i ++)
	{
		c[i] = fastread ();
		u[i] = fastread ();
		if (c[i] == 0) c[i] -= u[i];
		else nico.push (i), visit[i] = true; 
	}
	int x, y, val;
	for (int i = 1; i <= m; i ++)
	{
		x = fastread ();
		y = fastread ();
		val = fastread ();
		add (x, y, val);
		in[y] ++, out[x] ++;
	}
	
	while (!nico.empty ())
	{
		fro = nico.front ();
		nico.pop ();
		visit[fro] = false;
		if (c[fro] < 0) continue;
		for (int i = head[fro]; i; i = data[i].next)
		{
			t = data[i].dataspace;
			if (visit[t] == false)
			{
				c[t] += data[i].val * c[fro];
				nico.push (t);
				visit[t] = true;
			} else {
				c[t] += data[i].val * c[fro];
			}
		}
	}
	
	for (int i = 1; i <= n ; i ++)
	{
		if (out[i] == 0 && c[i] > 0)
		{
			output.push((OUT) {i});
		}
	}
	
	if (output.empty ())
	{
		puts ("NULL");
		return 0;
	}
	
	while (!output.empty ())
	{
		fastwritespace (output.top().dataspace);
		fastwriteline (c[output.top().dataspace]);
		output.pop ();
	}
	
	return 0;
}

inline void add (int x, int y, int val)
{
	cnt ++;
	data[cnt].dataspace = y;
	data[cnt].val = val;
	data[cnt].next = head[x];
	head[x] = cnt;
}
inline int fastread ()
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
inline void fastwrite (int x)
{
	if(x < 0) x = -x, putchar('-');
	if(x > 9) fastwrite(x / 10);
	putchar(x%10 + '0');
}
inline void fastwritespace (int x)
{
	fastwrite(x);
	putchar(' ');
}
inline void fastwriteline (int x)
{
	fastwrite(x);
	putchar('\n');
}
