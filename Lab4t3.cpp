#include<iostream>
#include<string.h>
using namespace std;

class DAStack
{
public:
	int top;
	int size;
	int*current;
	DAStack()
	{
		top = -1;
		size = 5;
		current = new int[size];
	}
	bool isEmpty(){//Same function from static list
		return top == -1;
	}
	bool isFull()
	{
		if (top == size)
		{
			//expansion();
		}
		return top == size;
	}
	void expansion()//Function to dynamically expand the list
	{
		size = size * 2;
		int *narr = new int[size];
		for (int i = 0; i<top; i++)
		{
			narr[i] = current[i];
		}
		delete[] current;
		current = narr;
		cout << "Expansion complete" <<endl;

	}
	void shrinking()//Function to dynamically shrink list
	{
		size = size / 2;
		int *narr = new int[size];
		for (int i = 0; i<top; i++)
		{
			narr[i] = current[i];
		}
		delete[] current;
		current = narr;
	}
	int pop()
	{
		if (!isEmpty())
		{
			int temp;
			temp = current[top];
			top--;
			// if (top <= size / 2)
			// 	shrinking();
			return temp;
		}
		else
			cout << "Array is empty" << endl;
		return -10;
	}
	void Peak()
	{
		if (!isEmpty())
		{
			cout << "Data at top of stack " << current[top] << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	void clear()
	{
		if (!isEmpty())
			top = -1;
		else
			cout << "Stack already empty" << endl;
	}
	void Push(int inp)
	{
		
			if (!isFull())
			{
				current[++top] = inp;
			
			}
		 else
		 {
		 	current[++top] = inp;
	 }
	}
	int peak_ret()
	{
		return current[top];
	}
	int precedence(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '/' || ch=='*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

};

int  main()
{
	DAStack stack;
	int i=0;
	string s;
	string postfix;
	char st;
	int val;
	char temp;
	bool validity=true;
	cout<<"Enter the input"<<endl;
	getline(cin,s);

	while(s[i]!='\0')
	{
		if(s[i] =='(' || s[i]== '['||s[i]=='{')
        {    
			val = (int)s[i];
            stack.Push(val);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}')       
        {

			if(stack.isEmpty())
			{
            validity= false;
			}
			st = (char)stack.pop();
			if(s[i]==')'&& st=='(')
			validity= true;
			else if(s[i]=='}'&& st=='{')
			{
			validity = true;

			}
			else if(s[i]==']'&& st=='[')
			validity= true;
        }
		i++;
	}
	stack.clear();
	if(validity==true)
	{
		cout<<"Is valid"<<endl;
		string postfix;
		int j=0;
		do
		{
			st=s[j];
			if(st>='0'&&st<='9')
			{
				postfix+=st;
			}
			else if(st=='('||st=='['||st=='{')
			{
				postfix+=' ';
				stack.Push((int)st);
			}
			else if(st==')'||st=='['||st=='{' )
			{	postfix+=' ';
				while(true)
				{
					postfix+=(char)stack.peak_ret();
					stack.pop();
					if((char)stack.peak_ret()=='(')
					{
					stack.pop();
					break;
					} 
				stack.pop();
				}
			}
			else if(stack.isEmpty()||stack.precedence(st)>stack.precedence((char)stack.peak_ret()))
			{	cout<<"Hello"<<endl;
				postfix+=' ';
				stack.Push((int)st);
			}
			else {
				postfix+=' ';
				cout<<"H";
				char d=(char)stack.peak_ret();
				while(!stack.isEmpty())
				{
					cout<<"f"<<endl;
					postfix+=(char)stack.peak_ret();
					stack.pop();

				}
				}
				j++;
				

			
		}while(j!=s.length()+1);
	
		cout<<postfix<<endl;
	
	}


}




