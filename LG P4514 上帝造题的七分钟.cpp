#prag\
ma G++ optimize ("Ofast", 3)
#prag\
ma GCC optimize ("Ofast", 3)
#prag\
ma GCC target ("sse3","sse2","sse")
#prag\
ma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma GCC target ("f16c")
#prag\
ma G++ target ("sse3","sse2","sse")
#prag\
ma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#prag\
ma G++ target ("f16c")

#include <stdio.h>

#define maxn 2050
#define rint register int
#define lowbit(x) x&-x

inline int read()
{
    register int x = 0, t = 1;
    register char ch = getchar();
    while ((ch<'0'||ch>'9')&&ch!='-') ch = getchar();
    if (ch=='-') t =-1, ch = getchar();
    while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    return x*t;
}

int n, m;

struct ELLIAS {
	int dat[maxn][maxn];
	
	inline void add (int x, int y, int val)
	{
		for (rint i = x; i <= n; i += lowbit(i))
		{
			for (rint j = y; j <= m; j += lowbit(j))
			{
				dat[i][j] += val;
			}
		}
	}
	inline int query (int x, int y)
	{
		register int ret = 0;
		for (rint i = x; i; i -= lowbit(i))
		{
			for (rint j = y; j; j -= lowbit(j))
			{
				ret += dat[i][j];
			}
		}
		return ret;
	}
} kianaOO, kianaXO, kianaOY, kianaXY;

inline int que (int x, int y)
{
	return \
	kianaOO.query (x, y) * (x * y + x + y + 1) + \
	kianaXY.query (x, y) - \
	kianaXO.query (x, y) * (y + 1) - \
	kianaOY.query (x, y) * (x + 1);
}

inline void add (int x, int y, int val)
{
	kianaOO.add (x, y, val);
	kianaXO.add (x, y, val * x);
	kianaOY.add (x, y, val * y);
	kianaXY.add (x, y, val * x * y); 
}

int main ()
{
	static char c[3];
	register int x1, y1, x2, y2, val;
	n = read (), m = read ();
	while (scanf ("%s", &c) != EOF)
	{
		x1 = read (), y1 = read (), x2 = read (), y2 = read ();
		
		if (c[0] == 'L')
		{
			val = read ();
			add (x1, y1, val), add (x1, y2+1, -val), \
			add (x2+1, y1, -val), add (x2+1, y2+1, val);
		} else printf ("%d\n", que(x2, y2)-que(x1-1, y2)-que(x2,y1-1)+que(x1-1, y1-1));
	}
	return 0;
}
