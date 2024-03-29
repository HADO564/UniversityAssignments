#include <iostream>
using namespace std; 
  
// A function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int count = 0;//count variable that counts the number of partitions made

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[(high+low)/2]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
     count++;
     cout<<count<<" Partition made"<<endl; 
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]);
    
    
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
        cout<<"Partitioned List is:"<<endl;
        for(int i = 0;i<pi;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(int i = pi+1;i<high;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    
    } 
} 
  

  

int main() 
{ 
    int arr[] = {40,20,10,80,60,50,7,30,100}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSort(arr, 0, n - 1); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    cout<<"\nNumber of partitions is: "<<count<<endl;
    return 0; 
} 