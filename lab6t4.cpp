#include<iostream>
#include<cstring>
using namespace std;

bool palindrome_check(string s, int start, int end)//function takes input, starting point of string 
//and ending point
{
    if(end-start==1 || start==end)//if the array is of 1 or 2 elements, return true
    {
        return true;
    }
    else
    {
        if(s[start]==s[end])//call function on next value of end and start
        {
            return palindrome_check(s,start+1,end-1); 
        }
        else
        {
            return false;
        }
    }
}



int main()
{
    string s;
    cout<<"Please enter a string to check if its a palindrome"<<endl;
    cin>>s;
    cout<<palindrome_check(s,0,s.length()-1);
    



}