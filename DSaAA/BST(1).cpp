#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

template<class T> class BiNode
{
public:
    T data;
	BiNode <T>  *lch;
	BiNode <T>  *rch;
	BiNode():lch(NULL),rch(NULL) { };
};

template<class T> class BST
{
public:
	BiNode<T> * Search(T key);
	void InsertBST(BiNode<T> *&r,BiNode<T>*s);
	void Delete(BiNode<T> *&R);
	bool DeleteBST(BiNode<T> *&R,T key);

    //已经实现 
	BST(T r[],int n);//构造函数 
	~BST();//析构函数
	void Inorder(BiNode<T> *R);//中序遍历，用来查看结果 
	void Release(BiNode<T> *R);//释放内存
    BiNode<T> *GetRoot(){return root;} //获取根节点 
    
private:	
	BiNode<T> *root;
	
};

template<class T>
void BST<T>::Inorder(BiNode<T> *R)
{
	if (R!=NULL)
	{
		Inorder(R->lch);
		cout<<R->data<<" ";
		Inorder(R->rch);
	}
}
template<class T>
void BST<T>::Release(BiNode<T> *R)
{
	if (R!=NULL)
	{
		Release(R->lch);
		Release(R->rch);
		delete R;
	}
}
template<class T>
BST<T>::~BST()//析构函数 
{
	Release(root); 
}
template<class T>
BST<T>::BST(T r[],int n)//构造函数 
{
	root = NULL;
	for (int i=0;i<n;i++)
	{
		BiNode<T> *s=new BiNode<T>;
       	s->data = r[i];       
       	s->lch = s->rch = NULL;
       	
       	InsertBST(root,s);
	}
		
}

template<class T>
void BST<T>::InsertBST(BiNode<T>*&r, BiNode<T>*s)
{
	
}

template<class T>
BiNode<T> * BST<T>::Search(T key)
{

}

int main()
{
	int a[]={63,90,70,55,67,42,98};
	BST<int> bt(a,7);
	bt.Inorder(bt.GetRoot());
	return 1;
}



