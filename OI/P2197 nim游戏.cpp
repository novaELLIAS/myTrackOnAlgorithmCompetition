#pragma GCC optimize ("Ofast")

#include <stdio.h>
#include <ctype.h>

#define rint register int
#define maxi 40000 
#define gc() (SS == TT && (TT = (SS = IN) + fread (IN, 1, MAXIN, stdin), SS == TT)? EOF:*SS++)
const int MAXIN = 40000;
char IN[MAXIN], *SS = IN, *TT = IN;

inline int read ()
{
	int x = 0; char c = gc(); bool m = 0;
	while (!isdigit(c) && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (m) return -x;
	else return x;
}

int n, ans;

int main ()
{
	int _ = read ();
	while (_ --)
	{
		n = read () - 1, ans  = read ();
		while (n --) ans ^= read ();
		if (ans) puts ("Yes");
		else puts ("No");
	}
	return 0;
}
