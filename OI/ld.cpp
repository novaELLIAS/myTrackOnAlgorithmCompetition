#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

inline char gc()
{
	static char buf[1<<14],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x)
{
	write (x); putchar ('\n');
}

inline const int& min (const int& a, const int& b) {return a<b? a:b;}

#define ELAS 12
#define Re register

/*
 ---*** Position Code ***---
	       0     1
    	   2     3
	4  5   6  7  8  9 10
    	  11    12
	13 14 15 16 17 18 19
    	  20    21
    	  22    23
 ---*********************---
*/

const int tab[8][7] = {
	{ 0,  2,  6, 11, 15, 20, 22}, /* len A */
	{ 1,  3,  8, 12, 17, 21, 23}, /* len B */
	{10,  9,  8,  7,  6,  5,  4}, /* len C */
	{19, 18, 17, 16, 15, 14, 13}, /* len D */
	{22, 20, 15, 11,  6,  2,  0}, /* len F */
	{23, 21, 17, 12,  8,  3,  1}, /* len E */
	{ 4,  5,  6,  7,  8,  9, 10}, /* len H */
	{13, 14, 15, 16, 17, 18, 19}  /* len G */
};
#define midmax 8
const int midle[8] = {15, 16, 17, 12, 8, 7, 6, 11};
const int retch[8] = {4, 5, 6, 7, 0, 1, 2, 3};

int dat[20];

inline void nico_move (register int x)
{
	register int tmp = dat[tab[x][0]];
	for (Re int i = 0; i ^ 6; i ++) dat[tab[x][i]] = dat[tab[x][i+1]];
	dat[tab[x][6]] = tmp;
}

inline bool exit_check ()
{
	for (Re int i = 1; i ^ midmax; i ++) if (dat[midle[0]] ^ dat[midle[i]]) return false;
	return true;
}

inline int exp_cal (register int x)
{
	register int ret = 0;
	for (Re int i = 0; i ^ midmax; ++ i) if (dat[midle[i]] ^ x) ++ ret;
	return ret;
}

inline int get_exp () {return min (exp_cal (1), min (exp_cal (2), exp_cal (3)));}

inline bool nico_dfs (Re int ste, Re int exp, Re int las)
{
	if (exit_check ()) return true;
	if (ste + get_exp() > exp) return false;
	for (Re int i = 0; i ^ 8; ++ i)
	{
		if (las ^ retch[i])
		{
			nico_move (i);
			if (nico_dfs (ste + 1, exp, i)) return true;
			nico_move (retch[i]);
		}
	}
	return false;
}

int main ()
{
	freopen ("ld.in", "r", stdin);
	freopen ("ld.out","w",stdout);
	
	register int firstinput, ans;
	while (true)
	{
		if (!(firstinput = read ())) break;
		dat[0] = firstinput;
		for (Re int i = 1; i ^ 24; ++ i) dat[i] = read ();
		for (ans = 0; ; ++ ans) if (nico_dfs (0, ans, -1)) break;
		writelen (ans);
	}
	return 0;
}
