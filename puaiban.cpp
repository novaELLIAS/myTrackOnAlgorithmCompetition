#pragma GCC optimize (2)
#pragma GCC optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],but[ELAS],*_p1=buf,*_p2=buf,*_p3=but,*_p4=but+ELAS;
static int bit[20];

#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}

//#define gc() getchar()
//#define pt(x) putchar(x)

inline long long read () {
	register long long x=0ll; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline long long readu () {
	register long long x=0ll; register char c=gc();
	while (c < '0' || c > '9') c = gc();
	while (c >='0' && c <='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}

typedef long long ll;
#define omd(a,b) ((a%b+b)%b)

inline long long gcd (int a, int b)
{
	if (!(a ^ b)) return a;
	return a>b? gcd(b, a-b):gcd(a, b-a);
}

inline void exgcd (ll a, ll b, ll &x, ll &y)
{
	if (!b) {x = 1, y = 0; return;}
	exgcd(b, a%b, y, x); y -= (a / b) * x;
}

signed main ()
{
	register long long _=readu(), a, b, c, gcdd, x, y;
	register long long tmpa, tmpb, tmpc, tmpd;
	register long long ansxa, ansxb, ansya, ansyb;
	while (_ --) {
		a=readu(), b=readu(), c=readu(), gcdd=gcd(a, b);
		if (c%gcdd) {pt('-'), pt('1'), pt('\n'); continue;}
		tmpa=a/gcdd, tmpb=b/gcdd, tmpc=c/gcdd; exgcd (tmpa, tmpb, x, y); x*=tmpc, y*=tmpc;
		ansxa=omd(x, tmpb), ansya=(c-a*ansxa)/b, ansxb=omd(y, tmpa), ansyb=(c-b*ansxb)/a;
		if (ansya<0 || ansyb<0) {pt('-'), pt('1'), pt('\n'); continue;}
		write(ansxa),pt(' '),write(ansya),pt(' '),write(ansxb),pt(' '),write(ansyb),pt('\n');
	} fwrite (but, 1, _p3-but, stdout); return 0;
}
