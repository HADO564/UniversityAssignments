#include<iostream> 
#include<cmath>
#include<ctime>
using namespace std;

class Queue//queue class
{
public:
	int static const size = 6;
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
	bool isEmpty()//checks if queue is empty
	{
		if (count == 0)
			return true;
		return false;
	}
	bool isFull()//checks if queue is full
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

	void Enqueue(int insert)
	{
		if (!isFull())//self explanatory
		{
			array[++last] = insert;
			count++;
			if (last == size - 1)
				last = start-1;
			cout << "Enqueued" << endl;
		}
		else
			cout << "Queue is full" <<endl;
	}
	int Dequeue()//self explanatory
	{
		if (!isEmpty())
		{
			cout << "Array dequeued" << endl;
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
	int First_ele()//returns first element of queue without dequeuing
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
	void length()//shows length of queue
	{
		if (!isEmpty())
		{
			cout << last - start + 1 << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	bool DocGoHome()//checks if doc can go home
	{
		return isEmpty();
	}
	void CancelAll()//cancels all appointments
	{
		if (!isEmpty())
		{
			last = -1;
			start = 0;
			count = 0;
			cout << "Appointments cancelled " << endl;
		}
		else
			cout << "No appointments already" << endl;
	}
	void RegPat(int x)//registers patients with a random id
	{
		if (!isFull())
		{
            last=(last+1)%size;
			array[last] = x;
			count++;

			cout << "Enqueued" << endl;
		}
		else
			cout << "Queue is full" << endl;
	}
	int ServePat()//dequeues a patient implying a patient is served
	{
		if (!isEmpty())
		{
			cout << "Array dequeued" << endl;
            start=(start+1)%size;
			count--;
			return array[start-1];
		}
		else
			cout << "Queue is empty" << endl;
		return -99;
	}
	void showall()//shows all patient ids(for convenience of coder)
	{
        if (last < start)
		{
            for(int i = start;i<size;i++)
            {
                cout << array[i] <<endl;
            }
			for (int i = 0; i <= last; i++)
			{
				cout << array[i] <<endl;
			}
		}
        else
        {
		for (int i = start; i <= last; i++)
		{
			cout << "Patient is " << array[i] << endl;
		}
        }
		
       
	}

};



int main(void)
{
	
	Queue Q1;
	srand(time(0));
    char d;//decision variable
    do
    {
      cout<<"1-Press A to register patient\t2-Press B to serve patient\n3-Press C to clear appointments\n4-Press D to check if doc can go home"<<endl;
      cout<<"5-Press E To show all patients\t6-Press Q to quit"<<endl;
      cin>>d;
      switch(toupper(d))//switch statement for decision making.
      {//simple UI using switch statement
            case 'A':
                cout<<"Patient registered"<<endl;
                Q1.RegPat(rand()%1000);
                break;
            case 'B':
                cout<<"Patient "<<Q1.ServePat() <<" Served"<<endl;
                break;
            case 'C':
                cout<<"All appointments canceled"<<endl;
                Q1.clear();
                break;
            case 'D':
                if (Q1.DocGoHome())
                cout << "Doctor can leave" << endl;
                else
                cout<<"Doctor cannot leave. Patients are in queue"<<endl;
                break;
            case 'E':
                cout<<"Showing patients"<<endl;
                Q1.showall();
                break;
            case 'Q':
                cout<<"Quitting"<<endl;
                break;
            default:
                cout<<"Please enter a valid input"<<endl;
      }
      cout<<"\n\n"<<endl;
    } while (d!='Q'&&d!='q');
    
	



	
}