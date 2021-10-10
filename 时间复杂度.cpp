#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
const int init = 1000000;
int t, l, w;
bool err = false;
string in;
string code[maxn];

int getnumber(int pos, string work)
{
	int ret = 0;
	//int pos = 3;
	while(work[pos] < '0' || work[pos] > '9'&& pos < work.size())
	{
		if(work[pos] == 'n')
		{
			pos++;
			return init;
		}
		pos++;
	}
	while(work[pos] >= '0' && work[pos] <= '9' && pos <work.size())
	{
		ret *= 10;
		ret += work[pos] - '0';
		pos++;
	}
	return ret;
}

int geto(string work)
{
	int ret = 0;
	int lenn = work.size();
	if(work[2] == 'n') ret = getnumber(3, work);
	else ret = 0;
	return ret;
}

int nier()
{
	int ret = 0;
	int now = 0;
	stack <int> s;
	int flag = -1;
	bool varjudge[26] = {false};
	bool nicovar[26] = {false};
	for(int i = 1; i <= l; i++)
	{
		if(code[i][0] == 'F')
		{
			int var = code[i][2] - 'a';
			if(varjudge[var]) return -1;
			s.push(var);
			varjudge[var] = true;
			int a = getnumber(4, code[i]);
			int b = getnumber(4, code[i]);
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
	else return ret;
}

int main()
{
	scanf("%d", &t);
	for(int times = 1; times <= t; times ++)
	{
		scanf("%d ", &l);
		if(l % 2 != 0)
		{
			puts("ERR");
			continue;
		}
		getline(cin,in);
		w = geto(in);
		for(int i = 1; i <= l; i++) getline(cin, code[i]);
		int w2 = nier();
		if(w2 == -1) puts("ERR");
		else
		{
			if(w2 == w) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
