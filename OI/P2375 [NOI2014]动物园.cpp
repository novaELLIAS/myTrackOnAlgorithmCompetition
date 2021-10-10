#include <stdio.h>
#include <string.h>

#define rint register int
#define modn 1000000007
#define maxl 1000001

static int n, pt;
static char s[maxl];
static int next[maxl], num[maxl];
static unsigned long long nico, lena;

int main ()
{
	scanf ("%d", &n);
	while (n --) {
		scanf ("%s", s);
		lena = strlen (s) - 1;
		next[0] = -1, pt = next[1] = num[0] = 0, num[1] = 1, nico=1ll;
		for (rint i = 1; i <= lena; i ++)
		{
			while (pt>=0 && s[i]!=s[pt]) pt = next[pt];
			next[i+1] = ++ pt, num[i+1] = num[pt] + 1;
		}
		pt = 0;
		
		for (rint i = 1; i <= lena; i ++)
		{
			while (pt>=0 && s[i]!=s[pt]) pt = next[pt];
			pt ++;
			while ((pt<<1) > (i+1)) pt = next[pt];
			nico = (nico*num[pt] + 1) % modn;
		}
		printf ("%lld\n", nico);
	}
	return 0;
}
