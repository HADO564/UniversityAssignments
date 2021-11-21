#include<iostream>
#include"BasicSorts.h"
using namespace std;

void swapping(int *b, int *c)
{
    int temp = *b;
    *b=*c;
    *c=temp;
}

void SelectionSort(int *a,int size)
{
    int min_ind;//index of the mininum number
    for (int i = 0; i<size-1;i++)
    {
        int min_ind=i;
        int j = i+1;
        while(j<size)
        {
            if(a[min_ind]>a[j])
            min_ind=j;
            j++;
        }
        swapping(&a[i],&a[min_ind]);
    }
}

void BubbleSort(int *a, int size)
{
    for(int i =0; i<size;i++)
    {
        for(int j = 0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
            swapping(&a[i],&a[j]);
            }
        }
    }
}

void ShortBubble(int *a, int size)
{
    bool swap =true;
    for(int i =0; i<size&&swap==true;i++)
    {
        swap=false;
        for(int j = 0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
            swapping(&a[i],&a[j]);
            swap=true;
            }
        }
    }
}