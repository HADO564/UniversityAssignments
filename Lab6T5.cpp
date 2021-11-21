#include<iostream>
using namespace std;

class node{
public:
int data;
node *next;
};

class list{

    public:
    node *start;
    node *last;
    int length=0;
    node *ploc;
    node *loc;
    list(){
        start=NULL;
        last=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return start==NULL;
    }
    void PrintList()
    { int i=1;
        if(!isEmpty())
        {
            node *temp = start;
            while(temp!=NULL)
            {
                cout<<"Position "<<i<<" Data"<<temp->data<<endl;
                temp = temp->next;
                i++;
            }
        }
        else
        cout<<"List is empty"<<endl;
    }
    void Search(int value)
    {
        loc=start;
        ploc=NULL;
        while(loc!=NULL && value>loc->data)
        {
            ploc=loc;
            loc=loc->next;
        }
        if(loc!=NULL && loc->data!=value)
        {
        loc=NULL;
        }
    }
    void InsertAtFront(int value)
    {
        node *newNode = new node;
        newNode->data=value;
        if(isEmpty())
        {
            start=newNode;
            last=newNode;
            newNode->next=NULL;
        }
        else{
            newNode->next=start;
            start=newNode;
        }
        length++;
    }
    void InsertValue(int value)
    {
        Search(value);
        if(loc==NULL)
        {
            if(ploc==NULL)
            InsertAtFront(value);
            else
            {
                node *newNode=new node;
                newNode->data=value;
                newNode->next=ploc->next;
                ploc->next=newNode;
                if(ploc==last)
                    last=newNode;
                length++;
            }
        }
        else{
            cout<<"Duplication not allowed"<<endl;
        }
    }
    void DeleteValue(int value)
    {
        if(!isEmpty())
        {
            Search(value);
            if(loc!=NULL)
            {
                if(start==last)
                {

                    start=NULL;
                    last=NULL;
                }
                else if(ploc==NULL)
                {
                    start=loc->next;
                    delete loc;
                    loc=start;
                    
                }
                else if(loc->next==NULL)
                {
                    delete last;
                    last=ploc;
                    ploc->next=NULL;
                }
                else
                {
                    cout<<"4"<<endl;
                    ploc->next=loc->next;
                    delete loc;
                    
                }
                length--;

            }
            else{
                cout<<"Value Not Found"<<endl;
            }
    
        }
    }
    void destroyList()
    {
        node* temp;
        while(start!=NULL)
        {
            temp=start;
            start=start->next;
            delete temp;
        }
        last=NULL;

    }
};

void printrev(node *rev)
{
    if(rev->next==NULL)
    {
        cout<<rev->data<<endl;//if last node is reached
        //print its data
    }
    else
    {
        printrev(rev->next);//call function befire printing data of current 
        //node
        cout<<rev->data<<endl;//print data of current node
    }
}

int main()
{
    list l1;
    cout<<"Enter values for insertion (-1 to quit)"<<endl;
    int x=0;
    while(x!=-1)
    {
        cin>>x;
        if(x!=-1)
        l1.InsertValue(x);
    }
    printrev(l1.start);
}