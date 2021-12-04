#include<iostream>
using namespace std;

void Merge(int arr[],int l_f, int l_l, int r_f, int r_l);//arr=array,l_f=left first, l_l=left last, r_f=right first, r_l=right last

void MergeSort(int arr[],int l_i, int r_i);//arr = array, l_i= left index, r_i=right index

void QuickSort(int arr[],int l,int r);

int partition(int *A,int l,int r);