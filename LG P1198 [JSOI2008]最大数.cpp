#pragma GCC optimize ("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>

#define rint register int
#define ll long long
#define maxn 200001

#define gc() getchar ()

inline long long read () {
	register long long x = 0; register char c = gc(); register bool flag = false;
	while (!isdigit(c) && c != '-') c = gc();
    if (c == '-') flag = true;
	while (isdigit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
	if (flag) return -x;
    else return x;
}

struct node
{
    long long x;
    int y;
} a[maxn];
int m,tot,cnt,f[maxn];
ll d,t,x,num[maxn];
char ch[3];
inline int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
int main()
{
    m = read(), d = read();
    for (rint i = 1; i <= m; i ++)
    {
        getchar();
        scanf ("%s %lld",ch, &x);
        if(ch[0]=='A')
        {
            x += t;
            x %= d;
            tot ++;
            num[tot] = x;
            f[tot] = tot;
            while (x > a[cnt].x && cnt)
            {
                f[a[cnt].y] = tot;
                cnt --;
            }
            a[++ cnt].x = x;
            a[cnt].y = tot;
        } else {
            x = tot - x + 1;
            int y = find(x);
            t = num[y];
            printf ("%lld\n", t);
        }
    }
    return 0;
}
