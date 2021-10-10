#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("inline")
#pragma GCC optimize ("-fgcse")
#pragma GCC optimize ("-fgcse-lm")
#pragma GCC optimize ("-fipa-sra")
#pragma GCC optimize ("-ftree-pre")
#pragma GCC optimize ("-ftree-vrp")
#pragma GCC optimize ("-fpeephole2")
#pragma GCC optimize ("-ffast-math")
#pragma GCC optimize ("-fsched-spec")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("-falign-jumps")
#pragma GCC optimize ("-falign-loops")
#pragma GCC optimize ("-falign-labels")
#pragma GCC optimize ("-fdevirtualize")
#pragma GCC optimize ("-fcaller-saves")
#pragma GCC optimize ("-fcrossjumping")
#pragma GCC optimize ("-fthread-jumps")
#pragma GCC optimize ("-funroll-loops")
#pragma GCC optimize ("-fwhole-program")
#pragma GCC optimize ("-freorder-blocks")
#pragma GCC optimize ("-fschedule-insns")
#pragma GCC optimize ("inline-functions")
#pragma GCC optimize ("-ftree-tail-merge")
#pragma GCC optimize ("-fschedule-insns2")
#pragma GCC optimize ("-fstrict-aliasing")
#pragma GCC optimize ("-fstrict-overflow")
#pragma GCC optimize ("-falign-functions")
#pragma GCC optimize ("-fcse-skip-blocks")
#pragma GCC optimize ("-fcse-follow-jumps")
#pragma GCC optimize ("-fsched-interblock")
#pragma GCC optimize ("-fpartial-inlining")
#pragma GCC optimize ("no-stack-protector")
#pragma GCC optimize ("-freorder-functions")
#pragma GCC optimize ("-findirect-inlining")
#pragma GCC optimize ("-fhoist-adjacent-loads")
#pragma GCC optimize ("-frerun-cse-after-loop")
#pragma GCC optimize ("inline-small-functions")
#pragma GCC optimize ("-finline-small-functions")
#pragma GCC optimize ("-ftree-switch-conversion")
#pragma GCC optimize ("-foptimize-sibling-calls")
#pragma GCC optimize ("-fexpensive-optimizations")
#pragma GCC optimize ("-funsafe-loop-optimizations")
#pragma GCC optimize ("inline-functions-called-once")
#pragma GCC optimize ("-fdelete-null-pointer-checks")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define Re register
#define maxn 1011
#define maxe 2011

struct EdgeNode {
	int to, nex, id;
	bool flag;
} e[maxe];
int head[35], ccnt;

string str[maxn];
int ind[35], oud[35], ansid[maxn], anspos;

inline void init ()
{
	ccnt = 0;
	memset (ind, 0, sizeof ind), memset (oud, 0, sizeof oud), memset (head, -1, sizeof head);
}

inline void nico_dfs (int x)
{
	for (Re int i = head[x]; i ^ (-1); i = e[i].nex)
	{
		if (!e[i].flag)
		{
			e[i].flag = true;
			nico_dfs (e[i].to);
			ansid[++ anspos] = e[i].id;
		}
	}
}

int main ()
{
	register int _, n, sta, u, v, oura1, oura2;
	scanf ("%d", &_);
	while (_ --)
	{
		scanf ("%d", &n);
		init ();
		for (Re int i = 0; i ^ n; ++ i) std::cin >> str[i];
		std::sort (str, str + n);
		
		sta = 100;
		for (Re int i = n - 1; i >= 0; -- i)
		{
			u = str[i][0] ^ 'a', v = str[i][str[i].length() - 1] ^ 'a';
			e[++ ccnt].to = v, e[ccnt].nex = head[u], e[ccnt].id = i, e[ccnt].flag = false, head[u] = ccnt;
			++ oud[u], ++ ind[v];
			sta = min (sta, min (u, v));
		}
		
		oura1 = oura2 = 0;
		for (Re int i = 0; i ^ 26; ++ i)
		{
			if (oud[i] - ind[i] == 1) ++ oura1, sta = i;
			else if (ind[i] - oud[i] == 1) ++ oura2;
			else if (oud[i] - ind[i]) oura1 = 3;
		}
		if (!((oura1 == 1 && oura2 == 1) || (!oura1 && !oura2))) {puts ("***"); continue;}
		anspos = 0;
		nico_dfs (sta);
		if (anspos ^ n) {puts ("***"); continue;}
		for (Re int i = anspos; i; -- i)
		{
			std::cout << str[ansid[i]];
			if (i ^ 1) putchar ('.');
		}
		putchar ('\n');
	}
	return 0;
}
