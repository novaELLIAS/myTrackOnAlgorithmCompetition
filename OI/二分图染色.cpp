
int n, m;
int head[MAXN], next[MAXM], to[MAXM], op;
int color[MAXN];

bool dfs(int u)
{
	for(int pos=head[u];pos;pos=next[pos])
	{
		// to[pos]表示一个和u相连的顶点 
		if(color[to[pos]] == 2)
		{
			color[to[pos]]=1-color[u];
			if(!dfs(to[pos])) return false;
		} else if (color[to[pos]] == color[u]) return false;
	}
	return true;
}

int main()
{
	// init,2表示没有被染色，0和1表示两种颜色 
	for(int i=1;i<=n;i++)
		color[i]=2;
	for(int i=1;i<=n;i++)
		if(color[i]==2)
		{
			color[i]=0;
			if(!dfs(i)){cout<<"NO"<<endl;return 0;}
		}
	cout<<"YES"<<endl;
}
