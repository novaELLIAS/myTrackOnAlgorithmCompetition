#include <bits/stdc++.h>
using namespace std;

int k, m;
vector <int> in;
int nico[30005], temp[30005];

void INIT()
{
	int t = 0;
	in.push(1);
	while(in.size() < k)
	{
		in.push_back(2*in[t] + 1);
		in.push_back(4*in[t] + 2);
		in.push_back(4*in[t] + 5);
		t++;
	}
}
void pushin(int x, int &pos)
{
	
}
void INSERT()
{
	k--;
	int t = k;
	for(int i = 0; i <= k; i++)
	{
		pushin(in[i],t);
	}
}
int main()
{
	scanf("%d%d",&k,&m);
	INIT();
	INSERT();
}
