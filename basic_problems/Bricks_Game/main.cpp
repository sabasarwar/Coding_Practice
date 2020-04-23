#include<iostream>
using namespace std;
 
int main()
{
    int n,i,a;
    cin>>n;
    a=0;i=1;
    
    while(a<=n)
    {
        a=a+i;
        if(a>=n)
        {
            cout<<"Patlu";
            break;
        }
        a=a+i*2;
        if(a>=n)
        {
            cout<<"Motu";
            break;
        }
        i++;
    }
    return 0;
}