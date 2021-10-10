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
#include <ctype.h>
#include <string.h>

#define rint register int
#define ll long long
#define modn 1000000007
#define xxxx 1000000005
#define maxn 102
#define maxp 502
#define maxa 100002

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}

inline int read()
{
    register int x=0ll; register char ch=gc();
    while((ch<'0'||ch>'9'))ch=gc();
    while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-48,ch=gc();
    return x;
}

inline void wwrite (long long x)
{
	if (x > 9) wwrite (x / 10);
	putchar (x % 10 + 48);
}

inline void write (long long x)
{
	if (x<0) putchar ('-'), x = -x;
	wwrite (x);
}

inline long long poww (long long x, int y){
	long long ans = 1;
	for (rint i = 30; i >= 0; i --)
	{
		ans = ans * ans % modn;
		if(y & (1 << i)) ans = ans * x % modn;
	}
	return ans;
}

inline long long get_inv (long long x)
{
	return poww (x, xxxx);
}

long long inv[100005], f[505], tab[10000005];
int a[105], des[505][105],d, p;

inline long long path (int a, int b)
{
	//puts ("ni");
	register long long ret = 1, sum = 0, del;
	for (rint i = 1; i <= d; i ++)
		if (des[a][i] > des[b][i]) return -1;
		else {
			del = des[b][i] - des[a][i];
			sum += del, ret = ret * inv[del] % modn;
		}
	return ret * tab[sum] % modn;
}
inline long long work (int x)
{
	//puts ("nico");
	register long long &ret = f[x], tmp;
	if (ret != -1) return ret;
	ret = path (0, x);
	for (rint i = 1; i <= p+1; i ++)
	{
		if (i != x)
		{
			tmp = path (i, x);
			if (tmp != -1) ret = (ret + modn - work (i) * tmp % modn) % modn;
		}
	}
	return ret;
}
int main ()
{
	freopen ("cube.in","r",stdin);
	freopen ("cube.out","w",stdout);
	d = read (), p = read ();
	for (rint i = 1; i <= d; i ++) a[i] = read();
	for (rint i = 1; i <= p; i ++)
	{
		for (rint j = 1; j <= d; j ++) des[i][j] = read ();
	}
	//puts ("check1");
	inv[0] = tab[0] = 1;
	for (rint i = 1; i <= 100000; i ++)
		inv[i] = inv[i-1] * get_inv(i) % modn;
	for (rint i = 1; i <= 10000001; i ++) tab[i] = tab[i-1] * i % modn;
	memset (f, 0xff, sizeof f); f[0] = 1;
	//puts ("check2");
	for (rint i = 1; i <= d; i ++) des[p+1][i] = a[i], des[0][i] = 0;
	//puts ("check3");
	printf ("%I64d", work(p+1));
	
	return 0;
}
