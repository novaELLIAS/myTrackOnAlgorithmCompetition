//�ڱ����У�����ֱ��ʹ��c��������ۼӣ�����û�п�a����
//<&x>Ϊ��ת���������ע���޹�
//������C++����

#include<cstdio>

int n, c[40000] = {0}, ans[16000] = {0};   //n:���ǵĸ���;c����:���ڹ�����״����;ans����:�����ۼ�;

//������������֤����ע��[1]��
inline int lowbit(const int &x);                      //lowbit:���ڼ���x^2
inline void doing_c(int x);                           //doing_c:���ڸ�����״����
inline int getsum(int x);                             //getsum:�������

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		++x;                                           //��״�����c[1]��ʼ������Ϊx=0ʱ��<&x>����whileѭ���������ѭ��
		++ans[getsum(x)];
		doing_c(x);
	}
	for(int i = 0; i < n ; ++i) {
		printf("%d\n", ans[i]);
	}
}

inline int lowbit(const int &x)
{
	return x & (-x);
}

inline void doing_c(int x)
{
	while (x <= 32001) {                                //<&x>�������봦��ʱ��x�����ֵδ֪��������Ŀ����ѭ��
		++c[x];
		x += lowbit(x);
	}
}

inline int getsum(int x)
{
	int s(0);
	while(x > 0) {
		s += c[x];
		x -= lowbit(x);
	}
	return s;
}
