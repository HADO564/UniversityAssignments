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
    node *nloc;
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
                cout<<"Position "<<i<<" Data "<<temp->data<<endl;
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
        /*if(isEmpty())
        {
        cout<<"List is empty"<<endl;
        return;
        }*/
        if(loc!=NULL && loc->data!=value)
        {
        loc=NULL;
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
    void printReverse(node *nextn)
    {
        if(nextn->next!=NULL)
        {
            printReverse(nextn->next);
        }
        cout<<"Data "<<nextn->data;
    }
    void ReverseOrder(node *begin)
     {
        loc = begin->next;
        ploc = NULL, nloc = NULL;
 
        while (loc != NULL) {
            nloc = loc->next;
            loc->next = ploc;
            ploc= loc;
            loc = nloc;
        }
        begin->next = ploc;
    }
    void DeleteOdd()
    {
        ploc=NULL;
        loc=start;
        while(loc!=NULL)
        {
            if(loc->data%2!=0)
            {
                node *temp= new node;
                if(loc==start)
                {
                    temp=loc->next;
                    delete loc;
                    loc=temp;
                    start=loc;
                    
                }
                else if(loc->next==NULL)
                {
                    delete last;
                    ploc->next=NULL;
                    last=ploc;
                    loc=start;
                    
                }
                else
                {
                    temp=loc->next;
                    delete loc;
                    ploc->next=temp;
                    loc=temp;
                    ploc=loc;
                    loc=loc->next;
                }       
            }
            else
            {
                ploc=loc;
                loc=loc->next;
            }
        }
    }
    void Grouping()
    {
    ploc = NULL;
    loc = start;
    node *new_last = last;
    while (loc->data % 2 == 0 && loc != last)
    {
        new_last->next = loc;
        loc = loc->next;
        new_last->next->next = NULL;
        new_last = new_last->next;
    }
    if (loc->data%2 != 0)
    {
        start = loc;
        while (loc != last)
        {
            if ( (loc->data) % 2 != 0 )
            {
                ploc = loc;
                loc = loc->next;
            }
            else
            {
                ploc->next = loc->next;
                loc->next = NULL;
                new_last->next = loc;
                new_last = loc;
                loc = ploc->next;
            }
        }
    }
    else 
    {
        ploc = loc;
    }
    if (new_last != last && (last->data) % 2 == 0)
    {
        ploc->next = last->next;
        last->next = NULL;
        new_last->next = last;
    }
    }
    void subset_R()
    {
        ploc=NULL;
        loc=start;
        if(isEmpty()) return;
        int i =1;
        node *temporary;
        node *oldlast=last;
        while(i<=length)
        {
            if(i%2==0)
            {
                temporary=loc;
                last->next=loc;
                ploc->next=temporary->next;
                last->next->next=NULL;
                last=last->next;
                loc=ploc->next;
            }
            else{
                ploc=loc;
                loc=loc->next;
            }
            i++;
        }
        ReverseOrder(oldlast);
    }
    void switchVals(int value1, int value2)
    {   loc=start;
        ploc=NULL;
        if(value1==value2)
        {
            cout<<"No Need to swap"<<endl;
            return;
        }
        Search(value1);
        if(loc==NULL)
        {
            cout<<"Value does not exist"<<endl;
            return;
        }
        node *plocv1=ploc;
        node *locv1=loc;
        loc=start;
        ploc=NULL;
        Search(value2);
        if(loc==NULL)
        {
            cout<<"Second value does not exist"<<endl;
            return;
        }
        node *plocv2=ploc;
        node *locv2=loc;
        if(plocv1!=NULL)
        {
            plocv1->next=locv2;
        }
        else start=locv2;

        if(plocv2!=NULL)
        {
            plocv2->next=locv1;
        }
        else start=locv1;
        node *tempo = locv2->next;
        locv2->next=locv1->next;
        locv1->next=tempo;
    }
};
int main()
{
    char dec='o';//Decision variable
    int ins;
    int ins2;
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
        newNode=l.start;
        l.InsertValue(ins);
        break;
        case 'B':
        cout<<"Insert value for deletion"<<endl;
        cin>>ins;
        l.DeleteValue(ins);
        break;
        case 'P':
        cout<<"The list is"<<endl;
        l.PrintList();
        break;
        case 'D':
        cout<<"The list is destroyed"<<endl;
        l.destroyList();
        break;
        case 'R':
        l.ReverseOrder(newNode);
        break;
        case 'O':
        l.DeleteOdd();
        break;
        case 'G':
        l.Grouping();
        break;
        case 'S':
        l.subset_R();
        break;
        case 'Q':
        cout<<"Quitting"<<endl;
        break;
        case 'C':
        cout<<"Please enter the two values"<<endl;
        cin>>ins>>ins2;
        l.switchVals(ins,ins2);
        break;
        default:
        cout<<"Please enter a valid input"<<endl;

    }
    }
}


