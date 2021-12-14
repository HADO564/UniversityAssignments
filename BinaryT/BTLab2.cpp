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
		if (isempty())
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (btt != NULL){

			postorderleaf(btt->lchild);
			postorderleaf(btt->rchild);

			if (btt->rchild == NULL && btt->lchild == NULL)
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
	void destroyT(node* current)
	{//function to destroy tree
		if (root == NULL)
		{
			cout << "Tree is already empty" << endl;
		}
		else if (current != NULL)
		{
			postorder(current->rchild);
			postorder(current->lchild);
			delete current;
		}
		root = NULL;
	}
	void counteach(node* current)//counts each node individually 
	{

		int static cl = 0;
		int static cr = 0;
		int static cb = 0;
		int static clf = 0;
		if (current != NULL)
		{
			counteach(current->lchild);
			counteach(current->rchild);
			if (current->lchild == NULL && current->rchild == NULL)
				clf++;
			if (current->lchild == NULL && current->rchild != NULL)
				cr++;
			if (current->lchild != NULL && current->rchild == NULL)
				cl++;
			if (current->lchild != NULL && current->rchild != NULL)
				cb++;
		}
		if (current == root)
		{
			cout << "Number of leaf nodes:" << clf << endl;
			cout << "Number of nodes with both childs:" << cb << endl;
			cout << "Number of nodes with only lchild:" << cl << endl;
			cout << "Number of nodes with only rchild:" << cr << endl;
		}
	}
	node* deleteleaf(node* root)
	{
		if (root == NULL)
			return NULL;
		if (root->lchild == NULL && root->rchild == NULL) {
			free(root);
			return NULL;
		}

		// Else recursively delete in left and right
		// subtrees.
		root->lchild = deleteleaf(root->lchild);
		root->rchild = deleteleaf(root->rchild);

		return root;
	}
	void deleteleftsub(node* current,node * pcurrent)//function to delete
    //nodes that only have left sub trees
	{
        if(current!=NULL)
        {
            deleteleftsub(current->lchild,current);//traverse the tree and delete such nodes
            //where found
            deleteleftsub(current->rchild,current);
            if(current->lchild!=NULL && current->rchild==NULL)
            {
                if(pcurrent->data>current->data)//check if the data is being deleted from
                //the left or the right child node
                {
                    pcurrent->lchild=current->lchild;
                    delete current;
                }
                else
                {
                    pcurrent->rchild=current->lchild;
                    delete current;
                }
            }
        }
	}
	};

	int main()//driver code
	{
		bt b;
		b.insert(4);
		b.insert(2);
		b.insert(3);
		b.insert(7);
		b.insert(1);
		b.insert(10);
		b.insert(6);
		b.insert(5);
		b.insert(0);
		cout << "Values in preorder" << endl;
		b.preorder(b.root);
		cout << "Values in postorder" << endl;
		b.postorder(b.root);
		cout << "Values in inorder" << endl;
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
		//b.destroyT(b.root);
		b.preorder(b.root);
		int x;
		cin >> x;
		b.counteach(b.root);
		//b.deleteleaf(b.root);
		//b.inorder(b.root);
		b.deleteleftsub(b.root, NULL);
		b.inorder(b.root);
	}
