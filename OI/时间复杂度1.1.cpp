#include <bits/stdc++.h>
using namespace std;

int t, l, w;
bool err = false;
string in;
string code[110];

int getnumber(int &pos, string work)
{
	int ret = 0;
	while(work[pos]<'0' || work[pos]>'9'&&pos<work.size())
	{
		if(work[pos]=='n')
		{
			pos++;
			return 1000000;
		}
		pos++;
	}
	while(work[pos]>='0'&&work[pos]<='9'&&pos<work.size())
	{
		ret *= 10;
		ret += work[pos] - '0';
		pos++;
	}
	return ret;
}

int geto()
{
	int x=3;
	if(in[2] == 'n') return getnumber(x, in);
	else return 0;
}

int nier()
{
	int ret = 0;
	int now = 0;
	stack <int> s;
	int flag = -1;
	bool varjudge[26] = {0};
	bool nicovar[26] = {0};
	for(int i = 1; i <= l; i++)
	{
		if(code[i][0] == 'F')
		{
			int var = code[i][2] - 'a';
			if(varjudge[var]) return -1;
			s.push(var);
			varjudge[var] = true;
			int x=4;
			int a = getnumber(x, code[i]);
			int b = getnumber(x, code[i]);
			if(b-a > 1000)
			{
				if(flag == -1)
				{
					now++;
					ret = max(ret, now);
					nicovar[var] = true;
				}
			}
			if(a > b)
			{
				if(flag == -1) flag = var;
			}
		}
		if(code[i][0] == 'E')
		{
			if(s.empty()) return -1;
			int var = s.top();
			s.pop();
			varjudge[var] = false;
			if(flag == var) flag = -1;
			if(nicovar[var])
			{
				nicovar[var] = false;
				now--;
			}
		}
	}
	if(s.size()) return -1;
	return ret;
}

int main(void)
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d ", &l);
		getline(cin,in);
		w = geto();
		for(int i = 1; i <= l; i++) getline(cin, code[i]);
		int w2 = nier();
		if(w2 == -1) puts("ERR");
		else
		{
			if(w2 == w) puts("Yes");
			else puts("No");
		}
	}
}
