// C++ program for Merge Sort
#include <iostream>
using namespace std;


int count= 0;


// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid, int const right)
{
    cout<<"Merging"<<endl;
    int const Arr1 = mid - left + 1;
    int const Arr2 = right - mid;
  
    // Create temp arrays
    int *l_Arr = new int[Arr1],
         *r_Arr = new int[Arr2];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < Arr1; i++)
        l_Arr[i] = array[left + i];
    for (int j = 0; j < Arr2; j++)
        r_Arr[j] = array[mid + 1 + j];
  
    int ind_arr1 = 0, // Initial index of first sub-array
        ind_arr2 = 0; // Initial index of second sub-array
    int ind_MARR = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (ind_arr1 < Arr1 && ind_arr2 < Arr2) {
        if (l_Arr[ind_arr1] <= r_Arr[ind_arr2]) {
            array[ind_MARR] = l_Arr[ind_arr1];
            ind_arr1++;
        }
        else {
            array[ind_MARR] = r_Arr[ind_arr2];
            ind_arr2++;
        }
        ind_MARR++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (ind_arr1 < Arr1) {
        array[ind_MARR] = l_Arr[ind_arr1];
        ind_arr1++;
        ind_MARR++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (ind_arr2 < Arr2) {
        array[ind_MARR] = r_Arr[ind_arr2];
        ind_arr2++;
        ind_MARR++;
    }
    int size = sizeof(array)/sizeof(array[1]);
    printArray(array,ind_MARR);
    cout<<endl;
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    cout<<"Merge Sort called"<<endl;
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
    count++;
}
  


int main()
{
    int arr[] = { 68,54,32,43,28,20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
    cout<<endl;
    mergeSort(arr, 0, arr_size - 1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    cout<<endl;
    cout<<"Number of partitions: "<< count<<endl;
    return 0;
}