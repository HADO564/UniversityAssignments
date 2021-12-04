#include<iostream>
#include"BasicSorts.cpp"
#include<stdlib.h>
#include<chrono>
using namespace std;
using namespace std::chrono;


int main()
{
    int arr[1000];
    int arr2[1000];
    int arr3[1000];
    srand(time(NULL));
    for(int i = 0;i<1000;i++)
    {
        arr[i]=rand()%10000;
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    } 
    auto start = high_resolution_clock::now();
    SelectionSort(arr,1000);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop - start);
    // for(int i = 0;i<100;i++)
    // {
    //     arr[i]=rand()%1000;
    // }
    auto start2 = high_resolution_clock::now();
    BubbleSort(arr2,1000);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    // for(int i = 0;i<100;i++)
    // {
    //     arr[i]=i;
    // }
    auto start3 = high_resolution_clock::now();
    ShortBubble(arr3,1000);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout<<"Time taken by each algorithm is "<<endl;
    cout<<duration1.count()<<" "<<duration2.count()<<" "<<duration3.count();


}