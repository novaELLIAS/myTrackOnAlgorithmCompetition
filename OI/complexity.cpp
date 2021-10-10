#pragma GCC optimize ("Ofast")

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stack>

using namespace std;

#define maxn 110
#define rint register int

string code [maxn], in;
bool varcheck[26], varcan[26];
stack <int> s;
int l, exp, rel, siz, var, a, b, flag;

inline int get_num (int &pos, string work)
{
	int ret = 0;
	while (!isdigit (work[pos]) && pos < work.size())
	{
		if (work[pos] == 'n')
		{
			pos ++;
			return 1000000;
		}
		pos++;
	}
	while(isdigit(work[pos]) && pos < work.size())
	{
		ret = ret * 10 + work[pos] - '0';
		pos++;
	}
	return ret;
}
inline int get_exp ()
{
	int x = 3;
	if (in[2] == 'n') return get_num (x, in);
	else return 0; 
}

inline int get_rel ()
{
	int ret = 0, now = 0;
	flag = -1;
	while (!s.empty()) s.pop ();
	memset (varcheck, 0, sizeof varcheck);
	memset (varcan, 0, sizeof varcan);
	for (rint i = 1; i <= l; i ++)
	{
		if (code[i][0] == 'F')
		{
			var = code[i][2] - 'a';
			if (varcheck[var]) return -1;
			s.push (var);
			varcheck[var] = true;
			int x = 4;
			a = get_num (x, code[i]);
			b = get_num (x, code[i]);
			if (b-a > 1000)
			{
				if (flag == -1)
				{
					now ++;
					ret = max (ret, now);
					varcan[var] = true;
				}
			}
			if (a > b && flag == -1) flag = var;
		}
		if (code[i][0] == 'E')
		{
			if (s.empty ()) return -1;
			var = s.top ();
			s.pop ();
			varcheck[var] = false;
			if (flag == var) flag = -1;
			if (varcan[var])
			{
				varcan[var] = false;
				now --;
			}
		}
	}
	if (s.size ()) return -1;
	else return ret;
}

int main ()
{
	freopen ("complexity.in","r",stdin);
	freopen ("complexity.out", "w", stdout);
	
	int _ ;
	scanf ("%d", &_);
	while (_ --)
	{
		scanf ("%d ", &l);
		getline (cin, in);
		exp = get_exp ();
		for (rint i = 1; i <= l; i ++) getline (cin, code[i]);
		rel = get_rel ();
		//cout << endl << exp << " " << rel << endl << "---------"<< endl;
		if (rel == -1) puts ("ERR");
		else {
			if(rel == exp) puts ("Yes");
			else puts ("No");
		}
	}
	return 0;
}
