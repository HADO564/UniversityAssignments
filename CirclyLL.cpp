#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};

class CirclyLL
{
    public:
    node *list;
    int length;
    node *loc;
    node *ploc;
    CirclyLL()
    {
        list=NULL;
        loc=NULL;
        ploc=NULL;
        length=0;
    }
    bool isEmpty()
    {
        return list==NULL;
    }
    void PrintList()
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
    void Search(int value)
    {
        if(!isEmpty())
        {
        // do
        // {
        //     if(loc->data != value && loc->next != NULL) 
        //     {
        //         loc = loc->next;
        //     }
        //     else if(loc==list->next&&value!=loc->data)
        //     {
        //         loc=NULL;
        //     }
        // } while (ploc!=list);
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
    void InsertSorted(int value)
    {
        if(!isEmpty())
        {
            Search(value);
            if(loc==NULL)
            {
              
                if(loc==list->next)
                {
                    insert_at_front(value);

                }
                else
                {
                    insert_mid(value);
                }
                
            }
            else
            {
                
                cout<<"Repetition not allowed"<<endl;
            }
        }
        else 
        insert_at_front(value);
    }
    void insert_mid(int value)
    {
        node *newnode= new node;
        newnode->data=value;
        newnode->next=ploc->next;
        ploc->next = newnode;    
        if (ploc==list)
        {
            list=newnode;
        }
        length++;
    }
    void insert_at_front(int value)
    {
        if(!isEmpty())
        {
        node *newnode= new node;
        newnode->data=value;
        newnode->next =ploc->next;
        ploc->next=newnode;

        }
        else if(isEmpty())
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
    void delete_node(int value)
    {
        if(!isEmpty())
        {
            Search(value);
            if(loc!=NULL)
            {
                cout<<"Value found"<<endl;
                if(loc==ploc)
                {
                    delete list;
                    list=NULL;
                }
                else
                {
                    if(loc==list)
                    {
                        ploc->next=list->next;
                        delete loc;
                        loc=ploc->next;
                        list=ploc;
                    }
                    else
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
    void destrolist()
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