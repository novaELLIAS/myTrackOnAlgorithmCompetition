#pragma GCC optimize ("Ofast", 3)
#pragma GCC optimize (3)
#pragma GCC optimize (2)
#pragma G++ optimize (3)
#pragma G++ optimize (2)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

#define Re register

struct QueueNode {
	string str;
	int ste;
};

queue <QueueNode> nico;
string ori, aim;
int all = 0;
string fro[6], to[6];
map <string, bool> sjb;

inline string work (const string &str, int pos, int tid)
{
	register string ret = "";
	if (pos + fro[tid].length() > str.length()) return ret;
	for (Re int i = 0; i ^ fro[tid].length(); ++ i)
		if (str[pos + i] ^ fro[tid][i]) return ret;
	ret = str.substr(0, pos);
	ret += to[tid], ret += str.substr(pos + fro[tid].length());
	return ret;
}

int main ()
{
	ios::sync_with_stdio (false);
	cin >> ori >> aim;
	while (cin >> fro[all] >> to[all]) ++ all;
	register QueueNode fr = {ori, 0}; nico.push(fr);
	register string transout;
	while (!nico.empty())
	{
		fr = nico.front(), nico.pop();
		if (fr.ste > 10) break;
		if (fr.str == aim) return printf ("%d", fr.ste), 0;
		if (!sjb.count(fr.str))
		{
			sjb[fr.str] = true;
			for (Re int i = 0; i ^ fr.str.length(); ++ i)
			{
				for (Re int j = 0; j ^ all; ++ j)
				{
					transout = work (fr.str, i, j);
					if (transout != "") nico.push((QueueNode){transout, fr.ste + 1});
				}
			}
		}
	}
	
	puts ("NO ANSWER!");
	
	return 0;
}
