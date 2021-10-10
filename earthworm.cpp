//#include<bits/stdc++.h>
#include <stdio.h>
#include "ctype.h"
#include<ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;
__gnu_pbds::priority_queue <int, less <int>, pairing_heap_tag> nico;
#define rint register int

inline int read ()
{
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, q, u, v, t, sum, a, b, size, fro;
double p;
//priority_queue <int> nico;

int main ()
{
	//freopen ("earthworm.in","r",stdin);
	//freopen ("earthworm.out","w",stdout);
	
	n = read (), m = read (), q = read (), u = read (), v = read (), t = read ();
	p = (double)u / (double) v;
	for (rint i = 1; i <= n; i ++) nico.push (read ());
	
	for (rint i = 1; i <= m; i ++)
	{
		fro = nico.top () + sum; nico.pop ();
		a = floor (p * (double)fro), b = fro - a;
		a -= (sum + q), b -= (sum + q);
		if (i % t == 0) printf ("%d ", fro);
		sum += q;
		nico.push (a), nico.push (b);
	}
	
	putchar ('\n');
	
	size = nico.size();
	for (rint i = 1; i <= size; i ++)
	{
		if (i % t == 0) printf ("%d ", nico.top () + sum);
		nico.pop ();
	}
	
	return 0;
}
