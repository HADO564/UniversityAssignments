#include<iostream>
#include"QandM.h"
using namespace std;

void Merge(int arr[],int l_f, int l_l, int r_f, int r_l)
{ 
    cout<<"Merging"<<endl;
    int temparr[l_f-r_l+1];
    int ind = l_f;
    int save= l_f;
    while((l_f<=l_l)&&(r_f<=r_l))
    {
        cout<<"Comparing and merging"<<endl;
        if(arr[l_f]<arr[r_f])
        {
            temparr[ind]=arr[l_f];
            l_f++;
        }
        else
        {
            temparr[ind]=arr[r_f];
            r_f++;
        }
        ind++;
    }
    cout<<"Merging left branch"<<endl;
    while(l_f<=l_l)
    {
        temparr[ind]=arr[l_f];
        l_f++;
        ind++;
    }
    cout<<"Merging right branch"<<endl;
    while(r_f<=r_l)
    {
        temparr[ind]=arr[r_f];
        r_f++;
        ind++;
    }
    cout<<"Making array"<<endl;
    for(ind = save; ind<=r_l;ind++)
    {
        arr[ind]=temparr[ind];
    }

}

void MergeSort(int arr[],int l_i, int r_i)
{
    if(l_i<r_i)
    {
        cout<<"Finding Mid"<<endl;
        int mid = (l_i+r_i)/2;
        cout<<"Mid found"<<endl;
        MergeSort(arr,l_i,mid);
        cout<<"Left mid"<<endl;
        MergeSort(arr,mid+1,r_i);
        cout<<"Right mid"<<endl;
        Merge(arr,l_i,mid,mid+1,r_i);
    }
}

int partition(int *A, int l, int r)
{
    int pivot_in = (l+r)/2;
    while(r>l)
    {
        while(A[l]<=A[pivot_in])
        l++;
        while(A[pivot_in]<A[r])
        r--;
        if(l<r)
        {
            int temp;
            temp = A[r];
            A[r]=A[l];
            A[l]=A[r];
        }
    }
    int temp2;
    temp2=A[r];
    A[r]=A[pivot_in];
    A[pivot_in]=temp2;
    return r;
}


void QuickSort(int arr[],int l,int r)
{
    int pivot = partition(arr,l,r);
    QuickSort(arr,l,pivot-1);
    QuickSort(arr,pivot+1,r);
}