/*
8 3
1 3 -1 -3 5 3 6 7

3
3
5
5
6
7
*/
#include <iostream>
using namespace std;

const int MAXN = 100000 + 10;
int n, k;
int data[MAXN];
int que[MAXN]; // 单调队列，值单调，存位置

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>data[i];
	// 输出每个窗口中的最大值
	
	int start=1,tail=0;
	for(int i=1;i<=k-1;i++)
	{
		// 放入元素
		while(start<=tail/*非空*/ && data[que[tail]]<=data[i])tail--;
		que[++tail]=i;
	}
	for(int i=k;i<=n;i++)
	{
		// 放入元素
		while(start<=tail && data[que[tail]]<=data[i])tail--;
		que[++tail]=i;
		
		if(que[start]+k<=i)start++;
		cout<<data[que[start]]<<endl;
	}
	
	return 0;
}
