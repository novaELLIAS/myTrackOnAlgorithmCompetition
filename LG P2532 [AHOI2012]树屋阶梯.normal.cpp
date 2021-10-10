#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <iostream>
#include <ctype.h>

using namespace std;

#define maxn 501
#define maxl 1001
#define ll long long
#define rint register int

string dp[maxn];
int n;

inline string add (string a, string b)
{
    string ret;
    rint dega[maxl] = {0}, nb[maxl] = {0}, lena = a.size(), lenb = b.size ();
    for (rint i = 0; i < lena; i ++) dega[lena - 1 - i] = a[i] - '0';
    for (rint i = 0; i < lenb; i ++) nb[lenb - 1 - i] = b[i] - '0';
    rint lmax = lena>lenb? lena:lenb;
    for (rint i = 0; i < lmax; i ++) dega[i] += nb[i], dega[i+1] += dega[i]/10, dega[i] %= 10;
    if (dega[lmax]) lmax ++;
    for (rint i = lmax-1; i >= 0; i --) ret += dega[i]+'0';
    return ret;
}
inline string mul (string a, int b)
{
    string ret;
    rint lena = a.size(), dega[maxl] = {0}, w = 0;
    for (rint i = lena - 1; i >= 0; i --) dega[lena - i - 1] = a[i] - '0';
    for (rint i = 0; i <lena; i ++) dega[i] = dega[i] * b + w, w = dega[i]/10, dega[i] = dega[i]%10;
    while(w) dega[lena ++] = w % 10, w /= 10;
    lena --;
    while (lena >= 0) ret += dega[lena--] + '0';
    return ret;
}
inline string dvi (string a, int b)
{
	string ret;
	rint x = 0, size = a.size () - 1;
	register bool flag = false;
	for (rint i = 0; i <= size; i ++) {
		x = (x * 10 + a[i] - '0');
		if (x >= b) {
			flag = true, ret += (x / b + '0'), x %= b;
		} else if(flag) ret += '0';
	}
	return ret;
}

int main ()
{
    ios::sync_with_stdio (false);
    cin >> n;
    dp[0] = dp[1] = "1";
    for (rint i = 2; i <= n; i ++) dp[i] = dvi(mul(dp[i-1], (4*i-2)), i+1);
    cout << dp[n] << endl;
    return 0;
}
