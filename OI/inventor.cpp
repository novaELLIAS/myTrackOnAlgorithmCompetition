#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <queue>

using namespace std;

const int ELAS = 1<<14;
inline char gc()
{
	static char buf[ELAS],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 150001

struct cmp {
	inline bool operator () (const int& a, const int& b)
	{
		return a > b;
	}
};

priority_queue <int, vector <int>, cmp> que;

inline const int& max (const int& a, const int& b)
{
	return a>b? a:b;
}

int main ()
{
	freopen ("inventor.in", "r", stdin);
	freopen ("inventor.out","w",stdout);
	
	register int n = read (), q = read (), maxans = -0x3f3f3f3f, in;
	while (n --) in = read(), maxans = max (maxans, in), que.push(in);
	while (q --)
	{
		if (read()) writelen (maxans);
		else {
			in = read (), maxans = max (maxans, in), que.push(in);
			writelen (que.top()), que.pop();
		}
	}
	return 0;
}
