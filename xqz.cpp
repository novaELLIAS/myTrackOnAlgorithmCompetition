#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + c - '0', c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x)
{
	write (x); putchar ('\n');
}

#define Re register
#define lowbit(x) ((x)&(-x))
#define maxm 1002005
#define ELAS 1000000

int dat[maxm];

inline void update (int x)
{
	register int y = x;
	while (x <= ELAS) dat[x] ^= y, x += lowbit (x);
}

inline int que (int x)
{
	register int ret = 0;
	while (x) ret ^= dat[x], x -= lowbit (x);
	return ret;
}

int main ()
{
	freopen ("xqz.in", "r", stdin);
	freopen ("xqz.out","w",stdout);
	
	register int m = read (), x, y, typ;
	while (m --)
	{
		typ = read ();
		if (typ ^ 3) x = read (), update (x);
		else x=read(),y=read(),writelen(que(y)^que(x-1));
	}
}
