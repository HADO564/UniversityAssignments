#include<iostream> 
using namespace std;

class Queue
{
public:
	int static const size = 6;
	int array[size];
	int start = 0;
	int last = -1;
	int count = 0;
	Queue()
	{
		start = 0;
		last = -1;
		array[size] = 0;
	}
	bool isEmpty()
	{
		if (count == 0)
			return true;
		return false;
	}
	bool isFull()
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
		if (!isFull())
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
	int Dequeue()
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
	int First_ele()
	{
		if (!isEmpty())
		{
			return array[start];
		}
		else
			cout << "Array is empty" << endl;
		return -99;
	}
	void clear()
	{
		if (!isEmpty())
		{
			last = -1;
			start = 0;
			count = 0;
                     cout << "Queue is cleared " << endl;
		}
		else
			cout << "Array is empty" << endl;
	}
	void length()
	{
		if (!isEmpty())
		{
			cout << last - start + 1 << endl;
		}
		else
			cout << "Array is empty" << endl;
	}

};



int main(void)
{
	Queue Q1;
	Q1.Enqueue(1);
	Q1.Enqueue(2);
	Q1.Enqueue(3);
	Q1.Enqueue(4);
	Q1.Enqueue(5);
	Q1.Enqueue(6);
	Q1.Enqueue(7);
	cout<<Q1.Dequeue()<<endl;
	cout << Q1.Dequeue() << endl;
	cout << Q1.Dequeue() << endl;
	cout << Q1.Dequeue() << endl;
	cout << Q1.Dequeue() << endl;
	cout << Q1.Dequeue() << endl;
	Q1.Enqueue(1);
	Q1.Enqueue(2);
	Q1.Enqueue(3);
	Q1.Enqueue(4);
	Q1.Enqueue(5);
	Q1.Enqueue(6);
	Q1.Enqueue(7);

}





if(currentNode!=NULL){

        printOnlyLeaf(currentNode->lChild);
        printOnlyLeaf(currentNode->rChild);
        
        if(currentNode->rChild == NULL && currentNode->lChild == NULL)
        cout << currentNode->data << " ";

    }
