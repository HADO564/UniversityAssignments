#include<iostream>
using namespace std;

class node//class for node object
{
    public:
    int data;
    node *next;
    node *prev;
};

class dlinkl//class for doubly linked list
{
    public:
    node *start;
    node *last;
    node *loc;
    int length;
    node* ploc;
    dlinkl()//constructor
    {
        start=NULL;
        last=NULL;
        loc=NULL;
        length= 0;
        ploc=NULL;
    }
    bool isEmpty()//bool function for checking if the list is empty or not
    {
        return start==NULL;
    }
    void search(int value)//search function for searching values.
    {
        loc=start;
        ploc=NULL;
        if(!isEmpty())//Checks if array is empty or not for searching
        {
            while(loc!=NULL&&loc->data<value)//while the data is less in magnitude compared to the value input by user
            {//run this loop
                ploc=loc;
                loc=loc->next;
            }
            if(loc!=NULL && loc->data!=value)//if condition to check if the while loop terminated because of inequality
            {//or equality
                loc=NULL;//in case of inequality, loc will be null
            }
        }
        else//else statement for an empty list
        cout<<"List is empty. Please enter a value first"<<endl;
            
    }
    void InsertSorted(int value)//function for sorting the input into of
    {// a user in a sorted manner into the list
        if(isEmpty())//if list is empty, insert at front and no need for searching for 
        {//duplicates
            InsertAtFront(value);
        }
        else if(!isEmpty())//if not empty search for duplicates
        {
            search(value);
            if(loc==NULL)//if no duplicate is found
            {
                
                if(ploc==NULL)//if the value is to be inserted at the front
                {
                    InsertAtFront(value);
                }
                else//if the value is inserted at any other location
                {
                    Insertion(value);
                }
                length++;//increment the length
            }
    
        }   
    }
    void InsertAtFront(int value)//function for inserting values at front
    {
        if(isEmpty())//if the list is empty, follow this procedure
        {
            node *newnode= new node;
            newnode->data= value;
            start=newnode;
            last=newnode;
            start->prev=NULL;
            return;
        }
        if(!isEmpty())//if the list isn't empty, follow this
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
    void Insertion(int value)//insertion at any point
    {
        if(ploc!=last)//if insertion is at any place other than the last
        {
            node *newnode= new node;
            newnode->data=value;
            newnode->next=ploc->next;
            newnode->prev=ploc;
            ploc->next->prev=newnode;
            ploc->next=newnode;
            return;
        }
        else//if the insertion is at the last place
        {
            node *newnode=new node;
            newnode->data=value;
            newnode->next=NULL;
            newnode->prev=last;
            last->next=newnode;
            last=newnode;
            return;
        }
    }
    void DeleteVal(int val)//deletion of values 
    {
        if(!isEmpty())
        {
            search(val);//search for input value
            if(loc!=NULL)//if value is found
            {
                if(start==last)//if there is only one element
                {
                    start=NULL;
                    last=NULL;
                }
                else if(ploc==NULL)//if there is more than one element
                {//and the first value is to be deleted
                    start=loc->next;
                    delete loc;
                }
                else if(loc==last)//if the last value is to be deleted
                {
                    last=last->prev;
                    delete loc;
                }
                else//if the value that is to be deleted is in the mid
                {
                    loc->next->prev=loc->prev;
                    loc->prev->next=loc->next;
                    delete loc;
                }
                length--;//decrement length after deletion
            }
        }
    }
    void DestroyList()//function for destroying list
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
    void PrintList()//printing fucntion
    {
        bool ord=false;//boolena for decision whether to print the list
        //in reverse or normal order
        
        cout<<"Would you like to print in normal or reverse order?"<<endl;
        cout<<"Press 1 to print in reverse order and 0 for normal order"<<endl;
        cin>>ord;
        
        if(ord==0)//function for printing in normal order
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
        else if(ord==1)//function for printing in reverse order
        {
            int j=length+1;
            if(!isEmpty())
            {
                node*temp=last;
                while(temp!=NULL)
                {
                    cout<<"Position "<<j<<" Data"<<temp->data<<endl;
                    temp=temp->prev;
                    j--;
                }
            }
            else
                cout<<"List is empty"<<endl;
        }
    }
};



int main()//driver function from previous linked list and circular list
//as the basic functionalities are the same
{
    char dec='o';//Decision variable
    int ins;//variable for insertion of data
    dlinkl l;
    while(dec!='Q'&&dec!='q')//loop for taking input from user and displaying output
    {//basic UI function
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
        system("cls");
        break;
        case 'Q':
        cout<<"Quitting"<<endl;
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}
