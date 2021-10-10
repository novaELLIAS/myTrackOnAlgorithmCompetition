#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast", 3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while (c!='-'&&(c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
template <typename T>
static void write (T x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

struct QueNode {
	int dat;
	int opt;
	int ste;
} que[7000001];
bool vis[10000001];
const int opti[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int main ()
{
	register int head = 0, tail = 1; 
}
