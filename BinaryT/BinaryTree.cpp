#include<iostream>
using namespace std;

class node 
{
    public:
    node* lchild;
    node* rchild;
    int data;
    node()
    {
        lchild=NULL;
        rchild=NULL;
    }
};
class bt
{
    public:
    node* root;
    node* loc;
    node* ploc;
    bt()
    {
        root=NULL;
        loc=NULL;
        ploc=NULL;
    }
    bool isempty()
    {
        return root==NULL;
    }
    void search(int value)
    {
        if(!isempty())
        {
            loc=root;
            ploc=NULL;
            while(loc!=NULL && loc->data!=value)
            {
                if(value<loc->data)
                {
                    ploc=loc;
                    loc=loc->lchild;
                }
                else
                {
                    ploc=loc;
                    loc=loc->rchild;
                }
            }
        }
        else
        {
            cout<<"Binary Tree is empty"<<endl;
        }
    }
    void insert(int value)
    {
        node* nn=new node;
        nn->data=value;
        
        if(!isempty())
        {
            search(value);
                if(loc==NULL)
                {
                    if(value<ploc->data)
                    {
                        ploc->lchild=nn;
                        cout<<ploc->lchild->data<<endl;
                    }
                    else
                    {
                        ploc->rchild=nn;
                        cout<<ploc->rchild->data<<endl;
                    }
                    
                    cout<<"value inserted"<<endl;
                }
                else{cout<<"dupliication not allowed"<<endl;}
        }
        else
        {
            root=nn;
            cout<<root->data<<endl;
        }
    }
    void preorder(node* btt)
    {
        if(btt!=NULL)
        {
            cout<<btt->data<<endl;
            preorder(btt->lchild);
            preorder(btt->rchild);

        }
    }
    void inorder(node*btt)
    {
        if(btt!=NULL)
        {
            inorder(btt->lchild);
            cout<<btt->data<<endl;
            inorder(btt->rchild);
        }
    }
    void postorder(node *btt)
    {
        if(btt!=NULL)
        {
            postorder(btt->lchild);
            postorder(btt->rchild);
            cout<<btt->data<<endl;
        }
    }
};
int main()
{
    bt b;
    b.insert(2);
    b.insert(1);
    b.insert(4);
    b.insert(0);
    b.preorder(b.root);
    
}