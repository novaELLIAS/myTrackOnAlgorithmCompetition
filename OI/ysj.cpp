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
static int bit[20];

#define gc() ((_p1==_p2)&&(_p2=(_p1=buf)+fread(buf,1,ELAS,stdin),_p1==_p2)?EOF:*_p1++)
inline void pt(char c) {
	(_p3==_p4)?(fwrite(_p3=but, 1, ELAS, stdout), *_p3++=c):(*_p3++=c);
}

//#define gc() getchar()
//#define pt(c) putchar(c)

inline long long read () {
	register long long x=0ll; register char c=gc(); register bool m=false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (!(c ^ '-')) c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline void write (long long x) {
	if (!x) {pt('0'); return;}
	register int pos=0;
	if (x < 0) x = -x, pt ('-');
	for (; x; x/=10) bit[++ pos] = x%10;
	for (register int i=pos; i; --i) pt(bit[i]^'0');
}
/*
inline long long mul_mod (register long long a,register long long b,register long long mo) {
	register long long ret;
	__asm__ __volatile__ ("\tmull %%ebx\n\tdivl %%ecx\n" : "=d"(ret):"a"(a),"b"(b),"c"(mo));
	return ret;
}
*/

inline long long mul_mod (register long long a,register long long b,register long long mo) {
	return (a*b)%mo;
}


inline long long qpow (long long a, long long t, long long modn) {
	register long long base = a, ret = 1ll;
	while (t) {
		if (t&1) ret = mul_mod(ret, base, modn);
		base = mul_mod(base, base, modn), t >>= 1;
	} return ret;
}

#define maxn 500001
#define init 500000

long long dmi[maxn][19], tab[maxn], phi[maxn], pri[maxn];
bool vis[maxn];

typedef long long ll;

signed main ()
{
	register int _ = read(), n=500001, cnt = 0, orin;
	register long long modn=read(), ans, dmp, tmpi, tmpj;
	
	for (register int i=1; i^n; ++i) dmi[i][0] = i;
	for (register int i=1; i<=18; ++i) {
		dmp=n-(1<<i); for (register int j=1; j^dmp; ++j) {
			dmi[j][i] = mul_mod(dmi[j][i-1], dmi[j+(1<<(i-1))][i-1], modn);
		}
	}
	
	tab[1] = phi[1] = 1;
	for (register int i=2; i^n; ++ i) {
		if (!vis[i]) phi[i]=i-1, pri[++ cnt]=i;
		for (register int j=1; j<=cnt; ++j) {
			dmp=i*pri[j];
			if (dmp>=n) break; vis[dmp]=true;
			if (!(i%pri[j])) {phi[dmp]=phi[i]*pri[j]; break;}
			phi[dmp]=phi[i]*phi[pri[j]];
		}
	}
	
	for (register int i=1; i^n; ++ i) tab[i]=tab[i-1]+phi[i];
	
	//for (register int i=1; i<=19; ++i) printf ("%d %d %d\n", phi[i], dmi[i][i], tab[i]);
	
	while (_ --) {
		n=(orin=read())+1, ans = 1ll;
		for (register int i=1, j=1; i^n; i=j+1) {
			j=orin/(orin/i), dmp = 1ll, tmpi=i, tmpj=j;
			if (tmpj-tmpi<=16) {
				for (register int k=tmpi; k<=tmpj; ++k) dmp=mul_mod(dmp, k, modn);
			} else {
				for (register int k=18; ~k; --k) {
					if (tmpi+(1<<k)<=tmpj+1) dmp=mul_mod (dmp, dmi[tmpi][k], modn), tmpi+=1<<k;
				}
			} ans = mul_mod(ans, qpow(dmp, (ll)(tab[orin/i]<<1)-1ll, modn), modn);
		} write (ans); pt('\n');
	} fwrite (but, 1, _p3-but, stdout); return 0;
}
