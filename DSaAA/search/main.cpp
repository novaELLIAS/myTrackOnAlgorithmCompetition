#include <iostream>
#include <queue>
#include <fstream>
#include <memory.h>
using namespace std;

template <class T,int N> class MGraph
{
public:
    MGraph(const char* filename);  //构造函数
    void DFS (int v);        //从v出发深度优先
    void BFS (int v);        //从v出发广度优先
    void PrintGraph();
    void DFS_process(int v);
private:
    T vertex[N];
    int arc[N][N];
    bool vis[N];
    int vNum, arcNum;      //顶点数、边数
};
template <class T,int N>
MGraph<T,N>::MGraph(const char* filename)  //构造函数
{
	ifstream in(filename);
	int i,j;
	in>>vNum>>arcNum;
	for (int i=0;i<vNum;i++)
	{
		in>>vertex[i];
	}
	 
	memset(arc,0,N*N*sizeof(int));
	while (!in.eof())
	{
		in>>i>>j;
		arc[i][j] = 1;
	}
	in.close();

}
template <class T,int N>
void MGraph<T,N>::PrintGraph()
{
	for (int i=0;i<vNum;i++)
		cout<<"v"<<vertex[i]<<" ";
	cout<<endl;
	for (int i=0;i<vNum;i++)
	{
		for (int j=0;j<vNum;j++)
			cout<<arc[i][j]<<" ";
		cout<<endl;
	}
}

template <class T, int N>
void MGraph<T,N>::DFS_process(int v) {
	printf("%d ", v); vis[v] = true;
	for (register int i=0; i^N; ++ i)
		if (!vis[i] && arc[v][i]) DFS_process(i);
	vis[v] = false;
}
template <class T,int N>
void MGraph<T,N>::DFS (int v)//从v出发深度优先
{
	memset(vis, 0, sizeof vis);
	DFS_process(v);
}
template <class T,int N>
void MGraph<T,N>::BFS (int v)    //从v出发广度优先
{
	memset (vis, 0, sizeof vis);
	register queue<int> que;
	while (!que.empty()) que.pop();
	que.push(v); vis[v] = true;
	register int fr;
	while (!que.empty()) {
		fr = que.front(); que.pop();
		printf("%d ", fr);
		for (register int i=0; i^N; ++ i)
			if (!vis[i] && arc[fr][i]) {
				que.push(i); vis[i] = true;
			}
		//vis[fr] = false;
	}
}

int main()
{
	MGraph<char,5> g("abc.txt");
	g.PrintGraph();
	g.DFS(2); putchar('\n');
	g.BFS(2); putchar('\n');
	return 0;
}
