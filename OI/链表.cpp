
// ��ͨ��д��
// ȱ�㣺��
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

// �ڴ��д�������ڴ�ص�0��λ�ÿ�ʼ����
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

// ����ģ��ָ��д�����ӵ�1����ʼ����
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

// ��ͼ�������
const int MAXN = 100, MAXM = 2000;
int head[MAXN], next[MAXM], to[MAXM], op;

void build(int a, int b) // ��һ����a��b�ĵ����
{
	next[++op]=head[a];head[a]=op;to[op]=b;
}
