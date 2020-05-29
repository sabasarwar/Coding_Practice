/* ----------------------------------- Problem Statement -------------------------------------

Rotate array by "d" elements using Juggling Algorithm : Inplace Method

Time Complexity : O(n*d)
Space Complexity : O(1)

---------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

void leftRotatebyOne(int arr[], int n)
{
    int temp=arr[0], i;
    for(i=0 ; i<n-1 ; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[i]=temp;
}

void leftRotate(int arr[], int n, int d)
{
    for(int i=0 ; i<d ; i++)
    {
        leftRotatebyOne(arr,n);
    }
}

void print(int arr[], int n)
{
    for(int i=0; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //Driver code to test functions
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    cout<<"\nOriginal Array : "<<endl;
    print(arr,n);
    
    leftRotate(arr, n, 3);
    //leftRotate(arr,n,3);
    //leftRotate(arr,n,5);
    
    cout<<"\nLeft Rotated Array upto d=3 places : "<<endl;
    print(arr,n);
    
    cout<<endl;
    return 0;
}

