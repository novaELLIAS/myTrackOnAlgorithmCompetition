#pragma G++ optimize ("Ofast", 3)

#include <cstdio>
#include <cmath> 

using namespace std;

#define Re register

int main ()
{
	freopen ("coin.in","r",stdin);
	freopen ("coin.out","w",stdout);
	
	register double R; scanf ("%lf", &R); register int _; scanf ("%d", &_); _ --;
	register double ans = 0.15470053837925152901829756100391 * R, d = 0.57735026918962576450914878050196 * R - ans;
	while (_ --) ans = d * d / (2.0 * (R + d)), d -= 2.0 * ans;
	printf ("%.6lf", ans);
	
	return 0;
}
