#include<iostream>
using namespace std;

class node{//node class
public:
int data;
node *next;
};

class list{//basic linked list class including functions

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
    
    void modPrintList()
    {   int i=1;
        if(!isEmpty())
        {
            node *temp = start;
            while(i<=length)
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

node* reverse(node* curr)
    {
        if (curr == NULL || curr->next == NULL)//base case. When end of list is reached
        //function will return the last node to be stored in stor.
            return curr;
        node* stor = reverse(curr->next);//the last node is stored in stor
        curr->next->next = curr;//the next field of the next node is updated
        //to store the current address
        
        curr->next = NULL;//the next field of the current node is nullified so that in the next recursive call
        //it is updated to store the address of its preceding field
 
        return stor;//after all the recursions have unwinded, the last node's address is stored in start
        //as shown in the main function 
    }







int main()
{
    list l1;
    cout<<"Enter numbers to insert into list(-1 to quit)"<<endl;
    int x;
    while(x!=-1)
    {
        cin>>x;
        if(x!=-1)
        l1.InsertValue(x);
    }
    l1.start=reverse(l1.start);
    l1.modPrintList();
}