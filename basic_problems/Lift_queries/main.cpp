#include <iostream>
using namespace std;
#include <math.h>
int main() 
{
    int T;
    cin>>T;
    int n[T];
    int i;
    for(i=0;i<T;i++)
    {
      cin >>n[i];
    }
    int A=0;
    int B=7;
     
    for(i=0;i<T;i++)
    {
        if(abs(n[i]-A)<=abs(B-n[i]))
        {
            cout<<"A"<<"\n";
            A=n[i];
        
        }
        else 
        {   cout << "B"<< "\n";
            B=n[i];
        }
    }
}