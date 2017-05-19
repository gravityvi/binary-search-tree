#include<iostream>

using namespace std;

template<typename E>
class BinaryTreeNode{
	E value;//the node's value
	BinaryTreeNode<E>* leftChild;//pointer to left child
	BinaryTreeNode<E>* rightChild;//pointer to right child
public:
	//constructors and destructors
	BinaryTreeNode(){
		leftChild=NULL;
		rightChild=NULL;
	}
	BinaryTreeNode(E e){
		value=e;
		leftChild=NULL;
		rightChild=NULL;
	}
	~BinaryTreeNode(){
		delete leftChild;delete rightChild;}

	//functions to det and get the value
	E& getValue(){return value;}

	void setValue(const E& e){ value=e;}

	//Functions to set and return the child
	inline BinaryTreeNode* left() const { return leftChild; }

	inline BinaryTreeNode* right() const { return rightChild; }

	void setRight(BinaryTreeNode<E>* b) { rightChild = b;}
	
	void setLeft(BinaryTreeNode<E>* b){leftChild = b; }
	
};

template<typename E>
class bst:public BinaryTreeNode<E>{
public:
BinaryTreeNode<E>* head;

	bst(){
	head=NULL;
}
void insert(BinaryTreeNode<E>* root,const E & ele)
	{
	BinaryTreeNode<E> *temp=new BinaryTreeNode<E>(ele);
	BinaryTreeNode<E> *current=root;
	BinaryTreeNode<E> *parent=NULL;
	if(root==NULL)
	{
		root=temp;
		head=temp;
	}
	else
	{
	while(1)
	{
		parent=current;
		if(current->getValue()>ele)
		{
			current=current->left();
			if(current==NULL)
			{
				parent->setLeft(temp);
				break;
			}
		}
		else
		{
			current=current->right();
			if(current==NULL)
			{
				parent->setRight(temp);
				break;
			}
		}
	}
	}
	
}

BinaryTreeNode<E>* findparent(BinaryTreeNode<E>* root,BinaryTreeNode<E>* son)//used in remove function
{
		
	BinaryTreeNode<E> *current=head;
	BinaryTreeNode<E> *parent=NULL;
	while(1)
	{
		parent=current;
		if(current->getValue()>son->getValue())
		{
			current=current->left();
			if(current==son)
			{
				return parent;
			}
		}
		else
		{
			current=current->right();
			if(current==son)
			{
				return parent;
			}
		}
	}
}
BinaryTreeNode<E>* search(BinaryTreeNode<E>* root,int element)
{
    BinaryTreeNode<E>* current=root;
    while(current->getValue()!=element)
    {
    	if(current->getValue()>element)
    	{
    		current=current->left();
    		
		}
		else
		{
			current=current->right();
		}
		if(current==NULL)
		return NULL;
	}
	return current;
}
BinaryTreeNode<int>* findmininrightsubtree(BinaryTreeNode<int>* root)
{
	int signal=0;
	BinaryTreeNode<int>* current=root->right();
	BinaryTreeNode<int>* min=current;
	BinaryTreeNode<int>* current1;
current1=current;
while(current1!=NULL)
	{
		
		if(min->getValue()>current1->getValue())
		{
			min=current1;
		}
		current1=current1->left();	
	}
	return min;
}


int inorderprint(BinaryTreeNode<E>* root){

   if(root==NULL)
   {
	return 0;
   }
   else
   {
	   inorderprint(root->left());
	   cout<<root->getValue()<<" ";
	   inorderprint(root->right());
   }
}

int  preorderprint(BinaryTreeNode<E>*root)
{

    if(root==NULL)return 0;
   	cout<<root->getdata()<<" ";
	preorderprint(root->left());
	preorderprint(root->right());
}

int postorderprint(BinaryTreeNode<E>* root){

    if(root==NULL)return;
	postorderprint(root->left());
	postorderprint(root->right());
	cout<<root->getvalue()<<" ";
}

void del(BinaryTreeNode<E>* p){
	int i;
	BinaryTreeNode<E>* c=p;
	if(p->right()==NULL)
		p->setRight(p->left());
	else{
		c=c->right();
		while(c->left()!=NULL){
			c=c->left();
		}
		c->setLeft(p->left());
	}
	e:
	i++;
}

void remove(BinaryTreeNode<E>* root,E data){
BinaryTreeNode<E>* temp=search(root,data);
BinaryTreeNode<E>* temp1;
BinaryTreeNode<E>* cmp1;

if((temp->left()==NULL)&&(temp->right()==NULL))
{
	
	
		temp1=findparent(root,temp);
		
	cmp1=temp1->left();
	
		if(cmp1==temp)
	{
	
		temp1->setLeft(NULL);
	}
	else
	{
		
		temp1->setRight(NULL);
		
	}
}
if((temp->left()==NULL)&&(temp->right()!=NULL))
{

	temp1=findparent(root,temp);
	cmp1=temp1->left();
	
	if(cmp1==temp)
	{
		temp1->setLeft(temp->right());
	}
	else
	{
		temp1->setRight(temp->right());
	}
	
}
if((temp->right()==NULL)&&(temp->left()!=NULL))
{
		temp1=findparent(root,temp);
	cmp1=temp1->left();

	if(cmp1==temp)
	{
		temp1->setLeft(temp->left());
	}
	else
	{
		temp1->setRight(temp->left());
	}
}
if((temp->right()!=NULL)&&(temp->left()!=NULL))
{

BinaryTreeNode<E>* min=findmininrightsubtree(temp);
temp->setValue(min->getValue());
remove(temp->right(),min->getValue());

}
}

};
int main(){
	
bst<int> s;
BinaryTreeNode<int>* temp;
//cout<<s.head<<endl;
s.insert(s.head,5);
s.insert(s.head,1); 
s.insert(s.head,2);
//cout<<s.head<<endl;
s.insert(s.head,3); 
s.insert(s.head,7);
s.insert(s.head,6);  
s.insert(s.head,8); 
s.insert(s.head,10); 
s.remove(s.head,7);


s.inorderprint(s.head);

   return 0;
}
