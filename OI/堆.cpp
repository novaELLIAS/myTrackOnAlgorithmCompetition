
struct Heap
{
	int data[MAXN];
	int size;
	
	Heap(){size = 0;}
	void up(int x)
	{
		while(x/2)
		{
			if(data[x/2]<data[x])swap(data[x/2], data[x]);
			x/=2;
		}
	}
	void down(int x)
	{
		while(true)
		{
			int pos = x;
			if(x*2<=size && data[x*2]>data[pos])pos=x*2;
			if(x*2+1<=size && data[x*2+1]>data[pos])pos=x*2+1;
			if(data[pos]>data[x])
			{
				swap(data[pos], data[x]);
				x=pos;
			} else break;
		}
	}
	void Insert(int value)
	{
		data[++size]=value;
		up(size);
	}
	int Top() { return data[1]; }
	void Pop()
	{
		swap(data[1], data[size]);
		size --;
		down(1);
	}
	bool Empty() { return size >= 1; }
};

Heap h;
h.Insert(10);
cout<<h.Top()<<endl;
h.Pop();

#include <queue>
using namespace std;
priority_queue<int> hque; // 优先队列：优先级大的先出队列，大根堆 
priority_queue<int, vector<int>, greater<int> > minque; // 小根堆 


