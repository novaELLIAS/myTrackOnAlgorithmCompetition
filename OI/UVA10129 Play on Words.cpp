#pragma G++ optimize (3) 

#include <cstdio>
#include <cstring>

#define maxn 26
#define maxl 1001
#define Re register

int ou[maxn], in[maxn];
bool mg[maxn][maxn], vis[maxn];
static char s[maxl];

static void nico_dfs (register int x)
{
	vis[x] = false;
	for (Re int i = 0; i ^ 26; ++ i)
		if (vis[i] && mg[x][i])
			nico_dfs (i);
}

int main ()
{
	register int _, n; scanf ("%d", &_);
	register int sta, end, fr, to, len;
	register int pos, cnt1, cnt2, cnt3;
	register bool flag;
	while (_ --)
	{
		scanf ("%d", &n);
		pos = cnt1 = cnt2 = cnt3 = flag = 0;
		for (Re int i = 0; i ^ 26; ++ i)
		{
			in[i] = ou[i] = vis[i] = 0;
			for(Re int j=0;j^26;++j) mg[i][j] = 0;
		}
		while (n --)
		{
			scanf ("%s", s); len = std::strlen (s);
			sta = s[0] - 'a', ++ ou[sta], vis[sta] = true;
			end = s[len-1]-'a',++ in[end],vis[end] = true;
			mg[sta][end] = true;
		}
		for (Re int i = 0; i ^ 26; ++ i)
		{
			//printf ("%d %d\n", in[i], ou[i]);
			if (in[i] ^ ou[i])
				if (ou[i] == in[i] + 1) ++ cnt1, pos = i;
				else if (in[i] == ou[i] + 1) ++ cnt2;
				else ++ cnt3;
		}
		//printf ("%d %d %d\n", cnt1, cnt2, cnt3);
		if (cnt3) puts ("The door cannot be opened.");
		else {
			if ((!cnt1 && !cnt2) || (cnt1 == 1 && cnt2 == 1)) flag = true;
			else {puts ("The door cannot be opened."); continue;}
			nico_dfs (pos);
			for (Re int i = 0; i ^ 26; ++ i) if (vis[i]) {flag=false;break;}
			if (flag) puts ("Ordering is possible.");
			else puts ("The door cannot be opened.");
		}
	}
	return 0;
}
