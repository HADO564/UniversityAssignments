#include<iostream>
using namespace std;

int cleaf = 0;//counter for leaf nodes
int cint = 0;//counter for internal nodes
class node//node class of binary tree
{
public:
	node* lchild;
	node* rchild;
	int data;
	node()
	{
		lchild = NULL;
		rchild = NULL;
	}
};
class bt//class of binary tree
{
public:
	node* root;
	node* loc;
	node* ploc;
	bt()//constructor
	{
		root = NULL;
		loc = NULL;
		ploc = NULL;
	}
	bool isempty()//checker function to see if tree is empty
	{
		return root == NULL;
	}
	void search(int value)//search function to avoid the repitition of values
	{
		if (!isempty())
		{
			loc = root;
			ploc = NULL;
			while (loc != NULL && loc->data != value)
			{
				if (value<loc->data)
				{
					ploc = loc;
					loc = loc->lchild;
				}
				else
				{
					ploc = loc;
					loc = loc->rchild;
				}
			}
		}
		else
		{
			cout << "Binary Tree is empty" << endl;
		}
	}
	void insert(int value)//insert function that inserts, first checking for duplicate values
	{
		node* nn = new node;
		nn->data = value;

		if (!isempty())
		{
			search(value);
			if (loc == NULL)
			{
				if (value<ploc->data)
				{
					ploc->lchild = nn;
					cout << "Left Node" << endl;
					cout << ploc->lchild->data << endl;
				}
				else
				{
					ploc->rchild = nn;
					cout << "Right Node" << endl;
					cout << ploc->rchild->data << endl;
				}

				cout << "value inserted" << endl;
			}
			else{ cout << "dupliication not allowed" << endl; }
		}
		else
		{
			root = nn;
			cout << root->data << endl;
		}
	}
	void preorder(node* btt)//prints the elements of the tree in preorder form
	{
		if (btt != NULL)
		{
			cout << btt->data << endl;
			preorder(btt->lchild);
			preorder(btt->rchild);

		}
	}
	void inorder(node*btt)//prints the elements of the tree in inorder form
	{
		if (btt != NULL)
		{
			inorder(btt->lchild);
			cout << btt->data << endl;
			inorder(btt->rchild);
		}
	}
	void postorder(node *btt)//prints the elements of the tree in post order form
	{
		if (btt != NULL)
		{
			postorder(btt->lchild);
			postorder(btt->rchild);
			cout << btt->data << endl;
		}
	}
	void printsmall(node * current)//prints the smallest value in the bst
	{
		if (!isempty())
		{
			if (current->lchild == NULL)
			{
				cout << current->data << endl;
			
			}
			else
			printsmall(current->lchild);
		}
	}
	void printlarge(node * current)//prints the largest value in bst
	{
		if (!isempty())
		{
			if (current->rchild == NULL)
			{
				cout << current->data << endl;

			}
			else
				printlarge(current->rchild);
		}
	}
	void postorderleaf(node *btt)//prints all of the leaf nodes
	{
        if(btt!=NULL){

        postorderleaf(btt->lchild);
        postorderleaf(btt->rchild);
        
        if(btt->rchild == NULL && btt->lchild == NULL)
        cout << btt->data << " ";

    }
	}

	void countleaf(node *btt)//counts all of the leaf nodes
	{
		if (btt != NULL)
		{
			countleaf(btt->lchild);
			countleaf(btt->rchild);
			if ((btt->lchild == NULL) && (btt->rchild == NULL))
			{

				cleaf++;

			}
		}
	}
	void countint(node *btt)//counts all the internal nodes
	{
		if (btt != NULL)
		{
			countint(btt->lchild);
			countint(btt->rchild);
			if (!((btt->lchild == NULL) && (btt->rchild == NULL)))
			{
				cint++;
			}
			
		}
	}
	int maxH(node* curr)//calculates the max height and depth of tree (both properties
	{//are the same, except if we count which node to start from
		if (curr == NULL)
			return -1;
		else
		{
			/* compute the depth of each subtree */
			int lH = maxH(curr->lchild);
			int rH = maxH(curr->rchild);

			/* use the larger one */
			if (lH > rH)
				return(lH + 1);
			else return(rH + 1);
		}
	}

};

int main()//driver code
{
	bt b;
	b.insert(2);
	b.insert(1);
	b.insert(4);
	b.insert(0);
	b.insert(-1);
	b.insert(3);
    cout<<"Values in preorder"<<endl;
	b.preorder(b.root);
    cout<<"Values in postorder"<<endl;
	b.postorder(b.root);
    cout<<"Values in inorder"<<endl;
	b.inorder(b.root);

	cout << "Lowest value is " << endl;
	b.printsmall(b.root);
	cout << "Largest value is " << endl;
	b.printlarge(b.root);
	b.postorderleaf(b.root);
	cout << "Number of leaf nodes is " << endl;
	b.countleaf(b.root);
	cout << cleaf << endl;
	cout << "Number of internal nodes is " << endl;
	b.countint(b.root);
	cout << cint << endl;
	cout << "Max height of the tree is " << endl;
	cout << b.maxH(b.root) << endl;
	cout << "Max Depth of the tree is " << endl;
	cout << b.maxH(b.root) << endl;
}