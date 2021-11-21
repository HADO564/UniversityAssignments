#include<iostream>
using namespace std;

int count=1;//global variable to count if node is even or odd

class node{//node class
public:
int data;
node *next;
};

class list{//list class

    public://basic linked list attributes and functions
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
void reverseodd(node *curr,node *prev,node *succ,list l)//function that reverses 
    //prev has address of previous node
    //curr has current node address
    //succ has successor node address
    //and pushes odd or even numbers to the end
    {
        if(curr!=NULL)//if end isn't reached
        {
            if(count%2==1)//if the count at that point is odd
            {
                count++;//increment
                prev=curr;
                succ=succ->next;//go to next node
                reverseodd(curr->next,prev,succ,l);//call function again
            }
            else//if the node is even
            {
                l.last->next=curr;//push current node to last
                prev->next=curr->next;//alter previous node address to next one(skipping the one pushed to last)
                l.last=l.last->next;//update last pointer to the new last node
                l.last->next=NULL;//change last node's next to null
                count++;//increment
                reverseodd(curr->next,prev,succ,l);//call function again
            }
        }
    }


int main ()//standard UI program
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
    cout<<"Press R to reverse some of the list"<<endl;
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
        case 'R':
        cout<<"Reversing"<<endl;
        reverseodd(l.start,NULL,l.start->next,l);
        count=1;
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}