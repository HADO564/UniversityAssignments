#include<iostream>
#include<string.h>
using namespace std;


class node
{
    public:
    int data;
    node *next;
};

class list
{
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
        cout<<"Boo"<<endl;
        while(loc!=NULL && value>loc->data)
        {
            ploc=loc;
            loc=loc->next;
            cout<<"Fuck"<<endl;
        }
        if(loc!=NULL && loc->data!=value)
        {
        loc=NULL;
        cout<<"Hello"<<endl;
        }
    }
    void InsertAtFront(int value)
    {
        cout<<"Insertion at front"<<endl;
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
                cout<<"Insertion at some place else"<<endl;
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
                cout<<"HALLO"<<endl;
                if(start==last)
                {
                    cout<<"0"<<endl;
                    start=NULL;
                    last=NULL;
                }
                else if(ploc==NULL)
                {
                    cout<<"1"<<endl;
                    start=loc->next;
                    delete loc;
                    loc=start;
                    
                }
                else if(loc->next==NULL)
                {
                    cout<<"3"<<endl;
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
int main()
{
    char dec='o';//Decision variable
    int ins;
    
    list l;
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
        l.InsertValue(ins);
        break;
        case 'B':
        cout<<"Insert value for deletion"<<endl;
        cin>>ins;
        l.DeleteValue(ins);
        break;
        case 'C':
        cout<<"The list is"<<endl;
        l.PrintList();
        break;
        case 'D':
        cout<<"The list is destroyed"<<endl;
        l.destroyList();
        break;
        case 'Q':
        cout<<"Quitting"<<endl;
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}


