#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>

#define gc() getchar()/*
#define gc() (SS == TT && (TT = (SS = IN) + fread (IN, 1, MAXIN, stdin), SS == TT)? EOF:*SS++)
#define rint register int
const int MAXIN = 40000;
char IN[MAXIN], *SS = IN, *TT = IN;
*/
inline int getint ()
{
	int x = 0; char c = gc(); bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

inline double getdou ()
{
	double x=0; char ch = getchar ();
	while (!isdigit(ch)) ch = getchar ();
	while (isdigit(ch)) x = x * 10 + (ch-48), ch = getchar ();
	if (ch == '.')
	{
		double s = 0.1;ch = getchar ();
		while (isdigit(ch)) x = x + (ch-48)*s,s/=10,ch = getchar ();
	}
	return x;
}


int n, pos = 1, exp;
double x[2], y[2], v[2], k;

int main()
{
	n = getint ();
	for (rint i = 1; i <= n; i ++, pos ^= 1)
	{
		exp = !pos, k = getdou ();
		x[pos] = (x[exp] + 1) * k;
		y[pos] = (y[exp] + 2*x[exp] + 1) * k;
		v[pos] = v[exp] + (3*x[exp] + 3*y[exp]+1) * k;
	}
	
	printf ("%.1lf", v[n&1]);
	
	return 0;
}
