#include<iostream>
#include"QandM.h"
#include"QandMSource.cpp"
using namespace std;

int main()
{
    int arr[3];//data set for merge sort
    cout<<"Enter values"<<endl;
    for (int i = 0; i < 3; i++)
    {
        cin>>arr[i];
    }
    int arr2[3];//data set for quick sort
    
    for (int i = 0; i < 3; i++)
    {
        cin>>arr[i];
    }
    cout<<"Values have been entered"<<endl;
    MergeSort(arr,0,3);
    cout<<"MergeSort done";
    QuickSort(arr2,0,2);
    for(int i = 0; i <sizeof(arr)/sizeof(int);i++)
    {
        cout<<arr[i]<<endl;
    }
    for(int i = 0; i <sizeof(arr2)/sizeof(int);i++)
    {
        cout<<arr[i]<<endl;
    }

}