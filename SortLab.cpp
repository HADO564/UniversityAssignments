#include<iostream>
#include<string.h>
using namespace std;

class node//class description for a single node in the linked list
{
public:
	int data;
	node *next;
};

class list //list class that will contain the nodes
{
public:
	node *start;//pointer pointing at start of list
	node *last;//pointer pointing at end of list
	int length = 0;//length of the list
	node *ploc;//pointer pointing to previous location (address) of node.
	node *loc;//pointer pointing at current location (address) of node.
	list(){//constructor for initializing linked lists
		start = NULL;
		last = NULL;
		length = 0;
	}
	bool isEmpty()//function for checking if list is empty
	{
		return start == NULL;
	}
	void PrintList()//function for printing linked list
	{
		int i = 1;
		if (!isEmpty())//checks if list is empty, in which case it won't print anything
		{
			node *temp = start;//points at start
			while (temp != NULL)//loop iterates until the value is null
				//which will only happen if list is empty or end of list is achieved
			{
				cout << "Position " << i << " Data" << temp->data << endl;
				temp = temp->next;
				i++;
			}
		}
		else
			cout << "List is empty" << endl;
	}
	void Search(int value)//Searching function for searching values to deletion or insertion
	{
		loc = start;
		ploc = NULL;
		while (loc != NULL && value>loc->data)
		{
			ploc = loc;
			loc = loc->next;
		}
		//*if(isEmpty())
		//{
		//cout<<"List is empty"<<endl;
		//return;
		//}*/
		//The above commented code is irrelevant to our needs
		if (loc != NULL && loc->data != value)
		{
			loc = NULL;
		}
	}
	void InsertAtFront(int value)//Insertion at front end function.
	{
		cout << "Insertion at front" << endl;
		node *newNode = new node;
		newNode->data = value;
		if (isEmpty())
		{
			start = newNode;
			last = newNode;
			newNode->next = NULL;
		}
		else{
			newNode->next = start;
			start = newNode;
		}
		length++;
	}
	void InsertValue(int value)//Function for the insertion of any value
		// which will be automatically sorted into the list
	{
		Search(value);//calls search function
		if (loc == NULL)
		{
			if (ploc == NULL)//ploc is null at front end
				InsertAtFront(value);
			else
			{
				node *newNode = new node;
				newNode->data = value;
				newNode->next = ploc->next;
				ploc->next = newNode;
				if (ploc == last)
					last = newNode;
				length++;
				cout << "Insertion at some place else" << endl;
			}
		}
		else{
			cout << "Duplication not allowed" << endl;
		}
	}
	void DeleteValue(int value)//Function for the deletion of the values. 
		// Value that is to be deleted will be searched using the search function
	{
		if (!isEmpty())//Checking if list is not empty
		{
			Search(value);//search function called to search for value
			if (loc != NULL)
			{

				if (start == last)//if there is only one node, this statement will be true
				{

					start = NULL;
					last = NULL;
				}
				else if (ploc == NULL)//if the node that is being searched is at the front end, this will be true
				{

					start = loc->next;
					delete loc;
					loc = start;

				}
				else if (loc->next == NULL)//If the node is at the tail end then this function will be called.
				{

					delete last;
					last = ploc;
					ploc->next = NULL;
				}
				else//lastly, if the function is in the middle, this part will run
				{

					ploc->next = loc->next;
					delete loc;

				}
				length--;

			}
			else{//part will run if value is not found
				cout << "Value Not Found" << endl;
			}

		}
		else
			cout << "List is empty" << endl;
	}
	void destroyList()//function for destruction of the list
	{
		node* temp;
		while (start != NULL)
		{
			temp = start;
			start = start->next;
			delete temp;
		}
		last = NULL;

	}
};
class Stack//stack class
{
public:
	int static const size = 6;//size of stack. Can be modified for different use
	int top;
	node* array[size];//array is of type node
	Stack()//constructor
	{
		top = -1;
		array[size];
	}
	void Push(node* inp)//push function
	{
		if (!isFull())
			array[++top] = inp;
		else
			cout << "Stack is full" << endl;

	}
	bool isFull()//checks if stack is full
	{
		return top == size;
	}
	bool isEmpty()//checks if stack is empty
	{
		return top == -1;
	}
	node* pop()//pops top element of stack
	{
		node *temp;
		if (!isEmpty())//checks if it is empty or not
		{
			
			temp = array[top];
			top--;
			return temp;
		}
		else
			cout << "Array is empty" << endl;
		temp =NULL;
		return temp;
	}
	void Peak()//displays top element of stack
	{
		if (!isEmpty())
		{
			cout << "Data at top of stack " << array[top] << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	void clear()//clears stack
	{
		if (!isEmpty())
			top = -1;
		else
			cout << "Stack already empty" << endl;
	}
};

void PrintRev(node** first,node**last)//reverses linked list using stack
{
	Stack s1;//stack declared
	node *temp =*first;//node type pointer to traverse linked list
	while (temp->next != NULL)
    {
         
        // Push all the nodes
        // in to stack
        s1.Push(temp);//push the address of nodes
        temp = temp->next;
    }
	*first = temp;//set last element as first element of list
	while(!s1.isEmpty())
	{
		temp->next=s1.pop(); //pop elements from  stack onto list 
		temp=temp->next;//go to next location
	}
	temp->next=NULL;//set last next to NULL
	*last=temp;//make current address
}

int main()
{
	char dec = 'o';//Decision variable
	int ins;//variable for insertion and deletion
	Stack s1;
	list l;
	while (dec != 'Q'&&dec != 'q')//loop in case someone wants to quit the program
	{
		node *newNode = new node;
		cout << "Press A to insert a value in a sorted manner" << endl;
		cout << "Press B to delete a value which will be searched" << endl;
		cout << "Press C to print the list" << endl;
		cout << "Press D to destroy the list" << endl;
		cout << "Press R to print in reverse" << endl;
		cout << "Press Q to quit " << endl;
		cin >> dec;
		switch (toupper(dec))//checks users input
		{//rest is self explanatory
		case 'A':
			cout << "Insert the value" << endl;
			cin >> ins;
			l.InsertValue(ins);
			break;
		case 'B':
			cout << "Insert value for deletion" << endl;
			cin >> ins;
			l.DeleteValue(ins);
			break;
		case 'C':
			cout << "The list is" << endl;
			l.PrintList();
			break;
		case 'D':
			cout << "The list is destroyed" << endl;
			l.destroyList();
			break;
		case 'R':
			cout << "Printing in reverse" << endl;
			PrintRev(&l.start,&l.last);

		case 'Q':
			cout << "Quitting" << endl;
			break;
		default:
			cout << "Please enter a valid input" << endl;

		}
	}
}
