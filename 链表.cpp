
// 普通的写法
// 缺点：慢
struct Node
{
	int value;
	Node* next;
};
Node *head = NULL;

void insert(int value)
{
	Node *p = new Node();
	p->value = value;
	p->next = head;
	head = p;
}

// 内存池写法，从内存池第0个位置开始储存
struct Node
{
	int value;
	Node *next;
};
Node pool[MAXN];
int poolTail=0;
Node *head = NULL;

void insert(int value)
{
	Node *p = &pool[poolTail++];
	p->value = value;
	p->next = head;
	head = p;
}

// 数组模拟指针写法，从第1个开始储存
int head = 0;
int value[MAXN], next[MAXN], prev[MAXN], tail = 0;

void insert(int _v)
{
	value[++tail] = _v;
	next[tail] = head;
	prev[head] = tail;
	head = tail;
}
void del(int pos)
{
	next[prev[pos]] = next[pos];
	prev[next[pos]] = prev[pos];
	if (pos == head) head = next[pos];
}

// 存图，单向边
const int MAXN = 100, MAXM = 2000;
int head[MAXN], next[MAXM], to[MAXM], op;

void build(int a, int b) // 建一条从a到b的单向边
{
	next[++op]=head[a];head[a]=op;to[op]=b;
}
