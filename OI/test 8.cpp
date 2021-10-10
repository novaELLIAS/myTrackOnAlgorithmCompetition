#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],but[ELAS],*_p1=buf,*_p2=buf,*_p3=but,*_p4=but+ELAS;
#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}

signed main ()
{
	freopen ("copycat.in", "r", stdin);
	//freopen ("copycat.out","w",stdout);
	register char c;
	do {c = gc();} while (c < '0' || c > '9');
	while (c >='0' && c <='9') c = gc();
	while ((c=gc()) != EOF) pt(c);
	return fwrite (but, 1, _p3-but, stdout), 0;
}
