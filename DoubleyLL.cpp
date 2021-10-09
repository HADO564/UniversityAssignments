#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
};

class dlinkl
{
    public:
    node *start;
    node *last;
    node *loc;
    int length;
    int pos;
    dlinkl()
    {
        start=NULL;
        last=NULL;
        loc=NULL;
        length= 0;
        pos=0;
    }
    bool isEmpty()
    {
        return start==NULL;
    }
    void search(int value)
    {
        pos=1;
        if(!isEmpty())
        {
            loc=start;
            while(loc!=last && loc->data<value)
            {
                loc=loc->next;
                pos++;
        
            }
            
            if(loc->data!=value)
            {
                loc->next=NULL;
                cout<<"Value does not exist"<<endl;
                return;
            }
            

            
        }
    }
    void InsertSorted(int value)
    {
        if(isEmpty())
        {
            InsertAtFront(value);
        }
        else if(!isEmpty())
        {
            search(value);
            if(loc->next==NULL)
            {
                
                if(loc==start&&loc->data>value)
                {
                    InsertAtFront(value);
                }
                else
                {
                    Insertion(value);
                }
                length++;
            }
            

    
        }   
    }
    void InsertAtFront(int value)
    {
        if(isEmpty())
        {
            node *newnode=new node;
            newnode->data=value;
            newnode->prev=NULL;
            newnode->next=NULL;
            start=newnode;
            last=start;
            length=1;
            return;
        }
        if(!isEmpty())
        {
            node *newnode=new node;
            newnode->data=value;
            newnode->prev=NULL;
            start->prev=newnode;
            newnode->next=start;
            start=newnode;
            return;
        }
    }
    void Insertion(int value)
    {
        node *newnode= new node;
        newnode->data=value;
        if(loc->data<value && loc!=NULL)
        {
             newnode->next=loc;
            newnode->prev=loc->prev->next;
            loc->prev->next=newnode;
            loc->prev=newnode;

        }
        else if(last->data<value)
        {
            newnode->prev=last;
            newnode->next=NULL;
            last->next=newnode;
            last=newnode;
        }
    }
    void DeleteVal(int val)
    {
        if(!isEmpty())
        {
            search(val);
            if(loc!=NULL)
            {
                if(start==last)
                {
                    start=NULL;
                    last=NULL;
                }
                else if(loc==start)
                {
                    start=loc->next;
                    delete loc;
                    loc=start;
                }
                else if(loc==last)
                {
                    last=last->prev;
                    delete loc;
                    loc=start;
                }
                else
                {
                    loc->next->prev=loc->prev;
                    loc->prev->next=loc->next;
                    delete loc;
                    loc=start;
                }
                length--;
            }
        }
    }
    void DestroyList()
    {
        if(!isEmpty())
        {
            node *temp=new node;
            
            while(start!=NULL)
            {
                temp=start;
                start=start->next;
                delete temp;
            }
        }
    }
    void PrintList()
    {
        int i=1;
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
};



int main()
{
    char dec='o';//Decision variable
    int ins;
    
    dlinkl l;
    while(dec!='Q'&&dec!='q')
    {
    node *newNode=new node;
    cout<<"Press A to insert a value in a sorted manner"<<endl;
    cout<<"Press B to delete a value which will be searched"<<endl;
    cout<<"Press C to print the list"<<endl;
    cout<<"Press D to destroy the list"<<endl;
    cout<<"Press Q to quit "<<endl;
    cin>>dec;
    switch(toupper(dec))
    {
        case 'A':
        cout<<"Insert the value"<<endl;
        cin>>ins;
        l.InsertSorted(ins);
        break;
        case 'B':
        cout<<"Insert value for deletion"<<endl;
        cin>>ins;
        l.DeleteVal(ins);
        break;
        case 'C':
        cout<<"The list is"<<endl;
        l.PrintList();
        break;
        case 'D':
        cout<<"The list is destroyed"<<endl;
        l.DestroyList();
        break;
        case 'Q':
        cout<<"Quitting"<<endl;
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}
