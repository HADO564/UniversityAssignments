#include<iostream>
using namespace std;

int factorial(int n)//factorial function
{
    if(n==0)//returns 1 when n = 0
    {
        cout<<"Case 0"<<endl;
        return 1;
    }
    
    else
    {
        cout<<"Case "<<n<<endl; 
        return n*(factorial (n-1));/*follows the formula of a factorial of n being
        equal to n(n-1)(n-2)(n-3)......*/   
       
    }
}

int fabonacci (int n)//function to calculate fabonacci till the nth term
{
    cout<<"Calling fib when N is "<<n<<endl;
    if(n<2)
    {
        cout<<"Base case achieved. Answer=1"<<endl;
        return n;
    }
    else
    {
        int sol = fabonacci(n-1)+fabonacci(n-2);
        cout<<"Case is "<<n<<". Answer="<<sol<<endl;
        return sol;
        
    }
}
bool found=false;//bool function used for searching

int search(int x[],int y,int j)//checks array, starting from 1st position
//j keeps track of position, not index
{
    int k;
    if(*x==y)
    {
        found =true;
        return j;
    }
    else
    {
        k= search(++x,y,++j);
        if(found==true)
        {
            return k;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int x1=5;//variable for factorial function
    int x[10];//varaible to hold user input
    int y;//used to store return value of fabonacci sequnce
    cout<<"Enter the integer to store in array"<<endl;
    for(int i = 0; i <6;i++)
    cin>>x[i];//taking input
    cout<<endl;
    cout<<"Enter number you wish to search in array"<<endl;
    cin>>y;
    cout<<"The element is at the "<<search(x,y,1)<<" position"<<endl; 
    cout<<factorial(x1);//outputting the result of the factorial function
    cout<<fabonacci(x1);//outputting the the result of the fabonacci sequence
    


}