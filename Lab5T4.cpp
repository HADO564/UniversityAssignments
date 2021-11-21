#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Queue
{
public:// queue class
	int static const size = 10;
	int array[size];
	int start = 0;
	int last = -1;
	int count = 0;
	Queue()//constructor
	{
		start = 0;
		last = -1;
		array[size] = 0;
	}
	bool isEmpty()//empty checking function
	{
		if (count == 0)
			return true;
		return false;
	}
	bool isFull()// Fullness checking fucntion
	{
		if (count==size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Enqueue(int insert)//enqueues items 
	{
		if (!isFull())
		{
			array[++last] = insert;
			count++;
			if (last == size - 1)
				last = start-1;
			//cout << "Enqueued" << endl;
		}
		else
			cout << "Queue is full" <<endl;
	}
	int Dequeue()//Dequeues item from queue
	{
		if (!isEmpty())
		{
			//cout << "Array dequeued" << endl;
			int temp = array[start];
			start++;
			count--;
			if (start == size)
			{
				start = 0;
			}
			return temp;
		}
		else
			cout << "Queue is empty" << endl;
		return -99;
	}
	int First_ele()//Returns first element of the queue, without dequeuing
	{
		if (!isEmpty())
		{
			return array[start];
		}
		else
			cout << "Array is empty" << endl;
		return -99;
	}
	void clear()//clears queue
	{
		if (!isEmpty())
		{
			last = -1;
			start = 0;
			cout << "Queue is cleared " << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	void length()//returns length of queue
	{
		if (!isEmpty())
		{
			cout << last - start + 1 << endl;
		} 
		else
			cout << "Array is empty" << endl;
	}
};

void bubbleSort(vector<int>& v)//bubble sort function for sorting vector
{
	if(v.size() == 0) return; 

    for(int max = v.size(); max > 0; max--) {
        for(int i = 1; i < max; i++)
		{
            int& current = v[i - 1]; //integer reference to current position of vector
            int& next = v[i];//integer reference to next position of vector
            if(current < next) 
                swap(current, next); //swapping algorithm in header files
        }
    }
}

int main()
{
    vector<int> arr;//declaration of first dynamic array
    char inp;//input char
    int inpi=0;//sum of input characters
	bool alter=false;//boolean to detect if some elements from the queues have been dequeud
    Queue Q0,Q1,Q2; //Three queues for %3=0,1 and 2.
    vector<int> coparr;//Vector array to store elements after some items have been dequeued
    cout<<"Enter the array of numbers. Press Q to quit entering input"<<endl;
    while(1)//loop that takes input until the input is Q
    {
        cin>>inp;
        if(inp!='q'&&inp!='Q')
        arr.push_back((int)inp-48);// converts the char to int and inserts to first vector;
        else 
        break;
    }
    for (auto i = arr.begin(); i != arr.end(); ++i)//loop that inserts values to the relative queues.
    {
        if(*i%3==0)
        {
            Q0.Enqueue(*i);
        }
        else if (*i%3==1)
        {
            Q1.Enqueue(*i);
        }
        else if (*i%3==2)
        {
            Q2.Enqueue(*i);
        }
        inpi = inpi+*i;//used to calculate the sum of the input numbers 
    }
		//if inpi%3==0, dont do anything, dequeue and sort in descending order
		alter=true;
		if(inpi%3==1)//if sum mod 3 == 1, either dequeu 1 element from queue of mod 1;
		{
			if(!Q1.isEmpty())
			{
				Q1.Dequeue();
				alter=true;
			}
			else//or 2 elements from queue of mod 2 if q1 is empty
			{
				for(int i = 0;i<2;i++)
				{
					if(Q2.isEmpty())
					{
						break;
					}
					else
					Q2.Dequeue();
					alter=true;
				}
				if(Q2.isEmpty())//if only one item is dequeued after which queue is empty
				{
					cout<<"Number is not possible"<<endl;
					alter=false;
					//break;
				}
			}
			
		}
		else if(inpi%3==2) ////if sum mod 3 == 2, either dequeu 1 element from queue of mod 2
		{
			if(!Q2.isEmpty())
			{
				Q2.Dequeue();
				alter=true;
			}
			else//or 2 elements from queue of mod 1 if q2 is empty
			{
				for(int i = 0;i<2;i++)
				{
					if(Q1.isEmpty())
					{
						break;
					}
					else
					Q1.Dequeue();
					alter=true;
				}
				if(Q1.isEmpty())//if only one item is dequeued after which queue is empty
				{
					cout<<"Number is not possible"<<endl;
					alter=false;
				}
			}
		}
		if(alter== true)// if after alteration, the value is multiple of 3
		//fill auxillary array (coparr)
		{
			while(!Q0.isEmpty())
			{
				coparr.push_back(Q0.Dequeue());
			}
			while(!Q1.isEmpty())
			{
				coparr.push_back(Q1.Dequeue());
			}
			while(!Q2.isEmpty())
			{
				coparr.push_back(Q2.Dequeue());
			}

			bubbleSort(coparr);//sort elements of coparr in decending order via bubble sort
		}
		
	for(auto i = coparr.begin();i!=coparr.end();i++)
	{
		cout<<*i<<" ";//output elements of coparr
	}

}
