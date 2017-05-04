#include "Arb-avl.h"

AVL::AVL()
{
	this->root = NULL;
}

AVL::~AVL()
{
}

int AVL::inaltime(node * q)
{
	int st_h = 0 , dr_h = 0;
	if (q != NULL)
	{
		if(q->left!=NULL)
		 st_h = 1+ inaltime(q->left);
		else if(q->right!=NULL)
		 dr_h = 1+ inaltime(q->right);
		else return 1;
		int maxh = max(st_h,dr_h);
		return maxh;
	}
	else return 0;
	
}

node * AVL::search(int z)
{
	node *q = this->root;
	while (q != NULL && z != q->key)
	{
		if (z > q->key)
			q = q->right;
		else q = q->left;
	}
	return q;
}

void AVL::In_order(node * q)
{
		if (q == NULL)
			return;
		In_order(q->left);
		cout<<q->key<<" ";
	In_order(q->right);
}

void AVL::Pre_order(node *q)
{
	if (q!= NULL)
	{
		cout << q->key<<" ";
		if (q->left != NULL)
			Pre_order(q->left);
		if (q->right != NULL)
			Pre_order(q->right);
	}
}

void AVL::Rot_left(node * q)
{
	node *y;
	y = q->right;
	q->right = y->left;
	if (y->left != NULL)
		y->left->p = q;
	y->p = q->p;
	if (q->p == NULL)
		this->root = y;
	else
	{
		if (q == q->p->left)
			q->p->left = y;
		else q->p->right = y;

	}
	y->left = q;
	q->p = y;
}
void AVL::Rot_right(node * q)
{
	{
		node *y;
		y = q->left;
		q->left = y->right;
		if (y->right != NULL)
			y->right->p = q;
		y->p = q->p;
		if (q->p == NULL)
			this->root = y;
		else
		{
			if (q == q->p->right)
				q->p->right = y;
			else q->p->left = y;

		}
		y->left = q;
		q->p = y;
	}
}

void AVL::FB(node *q)
{
	int st_h = inaltime(q->left);
	int dr_h = inaltime(q->right);
	q->fb = dr_h - st_h;

}


void AVL::insertie(int z)
{
	node *k;

	if (this->root == NULL)
	{
		this->root = new node;
		this->root->p = NULL;
		this->root->key = z;
		this->root->left = NULL;
		this->root->right = NULL;
	}
	else
	{
		node *q = new node;
		k = root;
		while (k != NULL)
		{
			q = k;
			if (z > k->key )
			{
				k = k->right;
			}
			else k = k->left;
		}
		
		k = new node;
		k->key = z;
		k->left = NULL;
		k->right = NULL;
		k->p = q;
		if (q->key > k->key)
		{
			q->left = k;
			repair(k->p,0);
		}
		else
		{
			q->right = k; 
			repair(k->p,1);
		}

		
	} 
	
}

void AVL::repair(node * k,int path)
{
	FB(k);
	if (k->fb == 0)
		return;
	if (k->fb != -2 || k->fb != 2)
	{
		if (k->p->left == k)
			path = 0;
		else path = 1;
		return repair(k->p, path);
	}
	else if (k->fb == -2)
	{
		node *y;
		if(path==0)
		y = k->left;
		else y = k->right;
		if (y->fb == -1)
			this->Rot_right(k);
		else if (y->fb == 1)
		{
			this->Rot_left(y);
			this->Rot_right(k);
		}
		if (k->p->left == k)
			path = 0;
		else path = 1;
		return repair(k->p, path);
	}
	else if (k->fb == 2)
	{
		
		node *y;
		if (path == 0)
			y = k->left;
		else y = k->right;
		if (y->fb == 1)
			this->Rot_left(k);
		else if (y->fb == -1)
		{
			this->Rot_right(y);
			this->Rot_left(k);
		}
		if (k->p->left == k)
			path = 0;
		else path = 1;
		return repair(k->p, path);
		
	}
	return;
}


