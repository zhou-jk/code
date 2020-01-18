#include <iostream>
using namespace std;
 
class Node
{
private:
	double key;
	Node *lchild;
	Node *rchild;
	Node *parent;
	friend class BST;
public:
	Node(double k = 0.0, Node *l = NULL, Node *r = NULL, Node *p = NULL) :key(k), lchild(l), rchild(r), parent(p){}
};
 
class BST
{
private:
	Node *root;
	void preOrder_Tree_Walk(Node *x)
	{
		if (x != NULL)
		{
			cout << x->key << " ";
			preOrder_Tree_Walk(x->lchild);
			preOrder_Tree_Walk(x->rchild);
		}
	}
	void inOrder_Tree_Walk(Node *x)
	{
		if (x != NULL)
		{
			inOrder_Tree_Walk(x->lchild);
			cout << x->key << " ";
			inOrder_Tree_Walk(x->rchild);
		}
	}
	void postOrder_Tree_Walk(Node *x)
	{
		if (x != NULL)
		{
			postOrder_Tree_Walk(x->lchild);
			postOrder_Tree_Walk(x->rchild);
			cout << x->key << " ";
		}
	}
	Node* tree_Search(Node *x, double k)
	{
		if (x == NULL || k == x->key)
			return x;
		if (k < x->key)
			return tree_Search(x->lchild, k);
		else
			return tree_Search(x->rchild, k);
	}
	Node* iterative_Tree_Search(Node *x, double k)
	{
		while (x != NULL && k != x->key)
		{
			if (k < x->key)
				x = x->lchild;
			else
				x = x->rchild;
		}
		return x;
	}
	Node* tree_Minimum(Node *x)
	{
		while (x->lchild != NULL)
			x = x->lchild;
		return x;
	}
	Node* tree_Maximum(Node *x)
	{
		while (x->rchild != NULL)
			x = x->rchild;
		return x;
	}
	Node* tree_Successor(Node *x)
	{
		Node *y = NULL;
		if (x->rchild != NULL)
			return tree_Minimum(x->rchild);
		y = x->parent;
		while (y != NULL && x == y->rchild)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	Node* tree_Predecessor(Node *x)
	{
		Node *y = NULL;
		if (x->lchild != NULL)
			return tree_Maximum(x->lchild);
		y = x->parent;
		while (y != NULL && x == y->lchild)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}
	void tree_Insert(Node *&T, Node *z)
	{
		Node *x = T;
		Node *y = NULL;
 
		while (x != NULL)
		{
			y = x;
			if (z->key < x->key)
				x = x->lchild;
			else
				x = x->rchild;
		}
		z->parent = y;
		if (y == NULL)
			T = z;
		else if (z->key < y->key)
			y->lchild = z;
		else
			y->rchild = z;
	}
 	void transplant(Node *&T, Node *u, Node *v)
	{
		if (u->parent == NULL)
			T = v;
		else if (u == u->parent->lchild)
			u->parent->lchild = v;
		else
			u->parent->rchild = v;
		if (v != NULL)
			v->parent = u->parent;
	}
	Node* tree_Delete(Node *&T, Node *z)
	{
		Node *y = NULL;
		if (z->lchild == NULL)
			transplant(T, z, z->rchild);
		else if (z->rchild == NULL)
			transplant(T, z, z->lchild);
		else
		{
			y = tree_Minimum(z->rchild);
			if (y->parent != z)	
			{
				transplant(T, y, y->rchild);
				y->rchild = z->rchild;
				y->rchild->parent = y;
			}
			transplant(T, z, y);
			y->lchild = z->lchild;
			y->lchild->parent = y;
		}
		return z;
	}
	void tree_Destory(Node *&T)
	{
		if (T == NULL)
			return;
		if (T->lchild != NULL)
			return tree_Destory(T->lchild);
		if (T->rchild != NULL)
			return tree_Destory(T->rchild);
 
		delete T;
		T = NULL;
	}
 
public:
	BST() :root(NULL){}
	void PreOrder_Tree_Walk()
	{
		preOrder_Tree_Walk(root);
		cout << endl;
	}
	void InOrder_Tree_Walk()
	{
		inOrder_Tree_Walk(root);
		cout << endl;
	}
	void PostOrder_Tree_Walk()
	{
		postOrder_Tree_Walk(root);
		cout << endl;
	}
	Node* Tree_Search(double key)
	{
		return tree_Search(root, key);
	}
	Node* Iterative_Tree_Search(double key)
	{
		return iterative_Tree_Search(root, key);
	}
	Node* Tree_Minimum(Node *x)
	{
		return tree_Minimum(x);
	}
	Node* Tree_Maximum(Node *x)
	{
		return tree_Maximum(x);
	}
	Node* Tree_Successor(Node *x)
	{
		return tree_Successor(x);
	}
	Node* Tree_Predecessor(Node *x)
	{
		return tree_Predecessor(x);
	}
	void Tree_Insert(double key)
	{
		Node *z = new Node(key, NULL, NULL, NULL);
		if (z == NULL)
			return;
		tree_Insert(root, z);
	}
	void Tree_Delete(double key)
	{
		Node *z, *node;
		z = iterative_Tree_Search(root, key);
		if (z != NULL)
		{
			node = tree_Delete(root, z);
			if (node != NULL)
				delete node;
		}
	}
	void Tree_Destory()
	{
		tree_Destory(root);
	}
 
	~BST()
	{
		Tree_Destory();
	}
};
 
int main()
{
	int i, j, n;
	double *arr;
 
	BST *tree = new BST();
 
	cout << "请输入结点/关键字个数: " << endl;
	cin >> n;
	arr = new double[n];
 
	cout << "请依次输入关键字(注意每棵子树的根节点都要比它的孩子结点先输入): " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		tree->Tree_Insert(arr[i]);
	}
	cout << endl;
 
	cout << "二叉搜索树先序遍历的结果为: ";
	tree->PreOrder_Tree_Walk();
	cout << "二叉搜索树中序遍历的结果为: ";
	tree->InOrder_Tree_Walk();
	cout << "二叉搜索树后序遍历的结果为: ";
	tree->PostOrder_Tree_Walk();
	cout << endl;
 
	double seaKey;
	cout << "请输入要查找的结点关键字: " << endl;
	cin >> seaKey;
	Node *seaNode = tree->Tree_Search(seaKey);
	if (seaNode)
		cout << "查找成功" << endl;
	else
		cout << "查找失败, 关键字为" << seaKey << "的结点不存在" << endl;
	cout << endl;
 
	double delKey;
	cout << "请输入要删除的结点关键字: " << endl;
	cin >> delKey;
	tree->Tree_Delete(delKey);
	cout << "删除操作后先序遍历二叉搜索树的结果为: ";
	tree->PreOrder_Tree_Walk();
	cout << "删除操作后中序遍历二叉搜索树的结果为: ";
	tree->InOrder_Tree_Walk();
	cout << endl;
 
	tree->Tree_Destory();
	delete[] arr;
	return 0;
}