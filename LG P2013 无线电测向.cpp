#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

#define gc() getchar()
#define rint register int
inline int read()
{
	register int x=0ll; register char ch=gc(); register bool t = false;
	while((ch<'0'||ch>'9') && ch!='-')ch=gc();
	if (ch == '-') t = true, ch = gc ();
	while(ch<='9'&&ch>='0')x=(x<<3)+(x<<1)+ch-48,ch=gc();
	if (t) return -x;
	return x;
}

map <char, int> xx, yy;

const double pp = 0.0174532925199432957;

int main ()
{
	register int n = read (), d;
	register char c;
	for (rint i = 1; i <= n; i ++)
	{
		scanf ("\n\r%c", &c);
		scanf ("%d %d", &xx[c], &yy[c]);
		//xx[c] = read (), yy[c] = read ();
	}
	
	n = read () - 90;
	scanf ("\n\r%c", &c);
	register int x1 = xx[c], y1 = yy[c];
	scanf ("%d", &d);
	d = 180 - n - d;
	register double k1 = tan (pp * d);
	
	scanf ("\n\r%c", &c);
	register int x2 = xx[c], y2 = yy[c];
	scanf ("%d", &d);
	d = 180 - n - d;
	register double k2 = tan (pp * d);
	
	register double kk=(y2-y1+k1*x1-k2*x2)/(k1-k2);
	printf ("%.2lf %.2lf", kk, k1*(kk-x1)+y1);
	return 0;
}
