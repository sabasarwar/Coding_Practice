/* ----------------------------------- Problem Statement -------------------------------------

Rotate array by "d" elements using Juggling Algorithm : Inplace Method

Time Complexity : O(n)
Space Complexity : O(1)

---------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

int findGCD(int a, int b)
{
    if(b==0)
        return a;
    else
        return findGCD(b, a%b);
}

void leftRotate(int arr[], int n, int d)
{
    int gcd = findGCD(n,d);
    
    for(int i=0 ; i<gcd ; i++)
    {
        int temp = arr[i];
        int j = i;
        while(1)
        {
            int k = (j+d) % n;
            if(k == i)
                break;
            
            arr[j] = arr[k];
            j = k;
        }
        
        arr[j] = temp;
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
    
    cout<<"\nLeft Rotated Array upto d=3 places : "<<endl;
    print(arr,n);
    
    cout<<endl;
    return 0;
}

