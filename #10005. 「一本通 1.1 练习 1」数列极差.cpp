#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cctype>
#include <queue>
#include <algorithm>

using namespace std;

#define rint register int


const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read () {
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x) {
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}

priority_queue<int, vector<int>, greater<int> > qg;
priority_queue<int, vector<int>, less<int> > ql;

signed main ()
{
	register int n=read (), m, x;
	for (rint i = 1; i <= n; ++ i) {
		x = read (); qg.push(x); ql.push(x); 
	}

	for (rint i = 2; i <= n; ++ i) {
		x = qg.top(); qg.pop(); x=x*qg.top()+1; qg.pop(); qg.push(x);
		x = ql.top(); ql.pop(); x=x*ql.top()+1; ql.pop(); ql.push(x);
	}
	
	printf ("%d", qg.top() - ql.top());
	
	return 0;
}
