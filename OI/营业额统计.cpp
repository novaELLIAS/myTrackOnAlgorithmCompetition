#include <algorithm>
struct Node
{
	int value;
	int id;
};
int n;
int data[MAXN], ans[MAXN];
Node nodes[MAXN];
int pos[MAXN]; // pos[1]表示data的第1的数排序之后在什么位置
int next[MAXN], prev[MAXN], value[MAXN];
bool cmp(const Node&A, const Node&B)
{
	return A.value < B.value;
}
int main()
{
	// read
	for(int i=1;i<=n;i++)
		nodes[i]=(Node){data[i], i};
	sort(nodes+1, nodes+1+n, cmp);
	for(int i=1;i<=n;i++)
		pos[nodes[i].id]=i;
	for(int i=1;i<=n;i++)
	{
		if(i>1)prev[i]=i-1;
		if(i<n)next[i]=i+1;
		value[i]=nodes[i].value;
	}
	for(int i=n;i>=1;i--)
	{
		ans[i]=1000000;
		if (next[pos[i]])
			ans[i]=min(ans[i], abs(value[pos[i]]-value[next[pos[i]]]));
		if (prev[pos[i]])
			ans[i]=min(ans[i], abs(value[pos[i]]-value[prev[pos[i]]]));
		next[prev[pos[i]]]=next[pos[i]]; // 删除
		prev[next[pos[i]]]=prev[pos[i]]; // 删除
	}
}
