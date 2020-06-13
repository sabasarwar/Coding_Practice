/* ----------------------------------- Problem Statement -------------------------------------

Rotate array by "d" elements using Reversal Algorithm.

Algorithm : Let AB are the two parts of the input array where A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is :

Reverse A to get ArB, where Ar is reverse of A.
Reverse B to get ArBr, where Br is reverse of B.
Reverse all to get (ArBr) r = BA.

Time Complexity : O(n)

---------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int n, int d)
{
    if(d == 0)
        return;
    
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
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
    int d=3;
    
    //in case the rotating factor => d is greater than array length => n
    d = d % n;
    
    cout<<"\nOriginal Array : "<<endl;
    print(arr,n);
    
    leftRotate(arr, n, d);
    
    cout<<"\nLeft Rotated Array upto d=3 places : "<<endl;
    print(arr,n);
    cout<<endl;
    return 0;
}