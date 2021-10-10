#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"
#include <queue>
#include "math.h"

using namespace std;

#define max(a,b) a>b? a:b
#define min(a,b) a<b? a:b

#define maxs 100

inline int fastread ();
inline void fastwrite (int);
inline void fastwriteline (int);
inline void fastwritespace (int);

inline void get_the_4th_point (int, int, int, int, int, int, int);
inline int double_square (int);
inline void spfa ();

struct node
{
	int x, y;
	int bel;
} data[maxs<<2|1];

int n, s, t, a, b, fro;
int tt[maxs|1];
double dis[maxs<<2|1];
bool visit[maxs<<2|1];
queue <int> nico;

int main ()
{
	n = fastread ();

	while (n --)
	{
		s = fastread ();
		t = fastread ();
		a = fastread ();
		b = fastread ();

		memset (data, 0, sizeof data);

		for (int i = 1; i <= s*4; i += 4)
		{
			data[i].x = fastread ();
			data[i].y = fastread ();
			data[i+1].x = fastread ();
			data[i+1].y = fastread ();
			data[i+2].x = fastread ();
			data[i+2].y = fastread ();
			data[i].bel = data[i+1].bel = data[i+2].bel = data[i+3].bel = i/4+1;
			tt[i/4+1] = fastread();
			get_the_4th_point (data[i].x, data[i].y, data[i+1].x, data[i+1].y, data[i+2].x, data[i+2].y,i);
		}
		
		spfa ();
		/*
		for (int i = (b<<2) - 3; i < b<<2; i ++)
		{
			printf ("%lf ", dis[i]);
			// fastwritespace (dis[i]);
		}
		
		puts ("nicojudge");
		*/
		double ans = dis[b<<2];
		for (int i = (b<<2) - 3; i < b<<2; i ++) ans = min (ans, dis[i]);
		printf ("%.1lf\n", ans);
	}
}

inline int double_square (int x)
{
	return x*x;
}

inline double distance (int x1, int y1, int x2, int y2)
{
	return sqrt (double_square(x1-y1) + double_square(x2-y2));
}

inline void get_the_4th_point (int x1, int y1, int x2, int y2, int x3, int y3, int i)
{
	int ab = double_square (x1-x2) + double_square (y1-y2),
	    ac = double_square (x1-x3) + double_square (y1-y3),
	    bc = double_square (x2-x3) + double_square (y2-y3);
	int x4,y4;
	if (ab + ac == bc) x4 = x2+x3-x1, y4 = y2+y3-y1;
	if (ab + bc == ac) x4 = x1+x3-x2, y4 = y1+y3-y2;
	if (ac + bc == ab) x4 = x1+x2-x3, y4 = y1+y2-y3;
	data[i+3].x = x4;
	data[i+3].y = y4;
}

inline void spfa()
{
	while (!nico.empty ()) nico.pop ();

	for (int i = 1; i <= s<<2; i ++) dis[i] = 2333333333.333;
	for (int i = (a<<2)-3; i <= a<<2; i ++)
	{
		dis[i] = 0;
		nico.push (i);
		visit[i] = true;
	}

	while (!nico.empty ())
	{
		fro = nico.front ();
		nico.pop ();
		visit[fro] = false;
		for (int i = 1; i <= s<<2; i ++)
		{
			if (i == fro) continue;
			double cost = distance (data[fro].x, data[i].x, data[fro].y, data[i].y);
			cost *= data[i].bel==data[fro].bel? tt[data[i].bel]:t;
			if (dis[fro] + cost < dis[i])
			{
				dis[i] = dis[fro] + cost;
				if (!visit[i])
				{
					visit[i] = true;
					nico.push (i);
				}
			}
		}
	}
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
