#include<iostream>
using namespace std;

class node//class of node
{
    public:
    int data;
    node* next;
};

class CirclyLL//class of list
{
    public:
    node *list;
    int length;
    node *loc;
    node *ploc;
    CirclyLL()//constructor
    {
        list=NULL;
        loc=NULL;
        ploc=NULL;
        length=0;
    }
    bool isEmpty()//checking if list is empty
    {
        return list==NULL;
    }
    void PrintList()//function to print list
    {
        int i=1;
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        else{
            node *temp = list->next;
            do
            {
                cout<<"Position "<<i<<"  Data "<< temp->data<<endl;
                temp=temp->next;
                i++;
            }while(temp!=list->next);
        }
    }
    void Search(int value)//search function
    {
        if(!isEmpty())//only search if list isn't empty
        {
            loc = list->next;
            ploc = NULL;
            do
            {
                ploc=loc;
                loc=loc->next;
            } while (loc!=list->next && loc->data<value);

            if(loc!=NULL&& loc->data!=value)
            {
                loc=NULL;
                cout<<"Value does not exist"<<endl;
            }
        }

    }
    void InsertSorted(int value)//function for sorting input into list
    {
        if(!isEmpty())//only search if not empty
        {
            Search(value);
            if(loc==NULL)
            {
              
                if(loc==list->next)//insert at front if loc is back in original position
                {
                    insert_at_front(value);

                }
                else//else insert in mid
                {
                    insert_mid(value);
                }
                
            }
            else
            {
                
                cout<<"Repetition not allowed"<<endl;
            }
        }
        else //if list is empty, insert directly
        insert_at_front(value);
    }
    void insert_mid(int value)//function for insertion at mid
    {
        node *newnode= new node;
        newnode->data=value;
        newnode->next=ploc->next;
        ploc->next = newnode;    
        if (ploc==list)//if insertion is at last or list pointer
        {
            list=newnode;
        }
        length++;
    }
    void insert_at_front(int value)//insertion at first, or after the list pointer
    {
        if(!isEmpty())//if list is empty
        {
        node *newnode= new node;
        newnode->data=value;
        newnode->next =ploc->next;
        ploc->next=newnode;

        }
        else if(isEmpty())//if not empty
        {
            node *newnode = new node;
            newnode->data = value;
            newnode->next = newnode;
            list = newnode;
            loc = list;
            ploc = list;
        }
        length++;
    }
    void delete_node(int value)//deletion
    {
        if(!isEmpty())
        {
            Search(value);
            if(loc!=NULL)
            {
                cout<<"Value found"<<endl;
                if(loc==ploc)//if only one value
                {
                    delete list;
                    list=NULL;
                }
                else
                {
                    if(loc==list)//if deletion at list pointer
                    {
                        ploc->next=list->next;
                        delete loc;
                        loc=ploc->next;
                        list=ploc;
                    }
                    else//if at any other location
                    {
                        ploc->next=loc->next;
                        delete loc;
                        loc=ploc->next;
                    }
                }
                length--;
            }
            else
            {
                cout<<"Value not found"<<endl;
            }
        }
    }
    void destrolist()//destruction of list function
    {
        if(!isEmpty())
        {
            node *temp ;
            while(list->next!=list)
            {
                temp=list->next;
                list->next=list->next->next;
                delete temp;
            }
            delete list;
            list=NULL;
        }   


    }
    
};

int main()
{
    char dec='o';//Decision variable
    int ins;
    
    CirclyLL l;
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
        l.delete_node(ins);
        break;
        case 'C':
        cout<<"The list is"<<endl;
        l.PrintList();
        break;
        case 'D':
        cout<<"The list is destroyed"<<endl;
        l.destrolist();
        break;
        case 'Q':
        cout<<"Quitting"<<endl;
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}