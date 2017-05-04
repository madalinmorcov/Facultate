#include<iostream>
#include<algorithm>
using namespace std;

struct node
{	
	int key;
	int fb;
	node *left, *right,*p;
};

class AVL
{
public:
	node *root;
public:
	AVL();
	~AVL();
	void FB(node *q);
	int inaltime(node *q);
	node* search(int z);
	void In_order(node *q);
	void Pre_order(node *q);
	void Rot_left(node *q);
	void Rot_right(node * q);
	void insertie(int z);
	void stergere(int z);
	void repair(node *k,int path);
};


