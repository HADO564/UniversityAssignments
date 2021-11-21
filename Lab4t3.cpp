#include<iostream>
#include<string.h>
#include<cmath>
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
	void Peak()//displays the top variable
	{
		if (!isEmpty())
		{
			cout << "Data at top of stack " << current[top] << endl;
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
	void Push(int inp)//pushes the parameter into the stack
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
	int peak_ret()//returns the top variable without popping it. 
	//used for peaking at the stack at
	{
		return current[top];
	}
	int precedence(char ch) {//checks the presedence of the operator
	//at the top of the stack
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

int  main()//main function
{
	DAStack stack;//stack for finding validity of
	//infix statement and used to fill postfix string
	DAStack Eva;//stack used for the evaluation of postfix string
	//
	//	IT IS IMPORTANT TO USE * WHEN MULTIPLYING, EVEN WHEN PARENTHESES ARE INVOLVED
	//	E.G To write 9+2(3-1), write 9+2*(3-1) instead, as the program doesn't multiply 
	// 	when there are only parentheses involved
	cout<<"If you wish to multiply with a parenthesis, insert * between parenthesis and the outer number"<<endl;
	int i=0;
	string s;//Initial string for input
	string postfix;//postfix string used to store postfix after conversion
	char st;//a single char used to store the ith/jth character of either postfix or string s
	int val;//used for input of value to stack in int
	// which will store ASCII value
	bool validity=true;//boolean for checking validity of infix string
	cout<<"Enter the input"<<endl;
	getline(cin,s);

	//TASK 2 CHECKING FOR VALIDITY

	while(s[i]!='\0')//while not end of string
	{
		if(s[i] =='(' || s[i]== '['||s[i]=='{')//check if current character is open bracket
        {    //if it is open bracket, push its ascii value to stack
			val = (int)s[i];
            stack.Push(val);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}')//if it is closing bracket instead    
        {

			if(stack.isEmpty())//if stack is already empty, the infix string is 
			//not valid
			{
            validity= false;
			}
			st = (char)stack.pop();//pop top most character and store in st either way
			if(s[i]==')'&& st=='(')//if st has open bracket of same type in s[i] then valid
			validity= true;
			else if(s[i]=='}'&& st=='{')//if st has open bracket of same type in s[i] then valid
			{
			validity = true;

			}
			else if(s[i]==']'&& st=='[')//if st has open bracket of same type in s[i] then valid
			validity= true;
        }
		i++;
	}
	stack.clear();//clear stack of any values for reuse
	if(validity==true)//only if the infix string is valid should we proceed.
	{
		cout<<"Is valid"<<endl;
		
		//TASK 3 CONVERTING TO POSTFIX

		string postfix;//string for storing postfix value
		int j=0;//counter for the following loop
		do
		{
			st=s[j];//put jth value in st for comparison later on
			if(st>='0'&&st<='9')//if value is an int, append it into postfix string
			{
				postfix+=st;
			}
			else if(st=='('||st=='['||st=='{')//if value is an open bracket
			{//create space in postfix and push open bracket to stack
				postfix+=' ';
				stack.Push((int)st);
			}
			else if(st==')'||st==']'||st=='}' )//if closing bracket 
			{	postfix+=' ';//create space in postfix
				while(!stack.isEmpty())//keep looping till stack is empty
				{// unless an opening parentheses is encountered after popping
					if((char)stack.peak_ret()=='('||(char)stack.peak_ret()=='['||(char)stack.peak_ret()=='{')
					{//if character is an open bracket, pop without appending postfix string
					stack.pop();
					break;//break if an opening bracket is encountered
					} 
					else //else, keep appending postfix string from stack.
					{
					postfix+=(char)stack.peak_ret();
					stack.pop();
					}
				}
			}
			
			else if(stack.isEmpty()||stack.precedence(st)>stack.precedence((char)stack.peak_ret()))
			{//if stack is either empty or precedence of operator is greater than operator at top
				// of stack, then create space and push current operator
				postfix+=' ';
				
				stack.Push((int)st);
			}
			else if(stack.precedence(st)<=stack.precedence((char)stack.peak_ret()))
				{//if precedence is lower or equal, keep popping, unless a closing bracket is encountered
					//or stack is empty
					while(stack.peak_ret()!='(')
					{
						postfix+=(char)stack.pop();
						if(stack.isEmpty())//break if stack is empty
						break;
					}
					stack.Push((int)st);//push the current operator to stack after popping				
				}	
			else 
				{// if next few characters are not numbers then keep popping stack for 
					postfix+=' ';
					while(!stack.isEmpty())
					{
						postfix+=(char)stack.peak_ret();
						stack.pop();

					}
				}
				j++;
		}while(j!=s.length()+1);
			
			cout<<postfix<<endl;
			//print postfix expression


			//TASK 4 EVALUATION OF POSTFIX EXPRESSION

		// Scan all characters one by one
		for (i = 0; postfix[i]; ++i)
		{
			// If the scanned character is an operand (number here),
			// push it to the stack.
		
	
			if(postfix[i]==' ')// if the character is an empty space,
			//continue
			continue;

			else if (postfix[i]>='0' &&postfix[i]<='9')
			{
				int num=0;
				
				//extract full number
				while(postfix[i]>='0' &&postfix[i]<='9')
				{
				num = num * 10 + (int)(postfix[i] - '0');
					i++;
				}
				i--;
				
				//push the element in the stack
				Eva.Push(num);
			}
			// If the scanned character is an operator, pop two
			// elements from stack apply the operator
			else
			{
				int val1 = Eva.pop();
				int val2 = Eva.pop();
				switch (postfix[i])
				{
				case '+': Eva.Push(val2 + val1); break;
				case '-': Eva.Push(val2 - val1); break;
				case '*': Eva.Push(val2 * val1); break;
				case '/': Eva.Push(val2 / val1); break;
				case '^': Eva.Push(pow(val2,val1)); break;
				}
			}
		}
		cout<<Eva.pop()<<endl;//after the termination of the while loop, print the resultant 
		// of the evaluation operation. 

	}
	else
	cout<<"Invalid Infix string"<<endl;
}




