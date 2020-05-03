
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int i,num,fact=1;
    cin>>num;
    for(i=1;i<=num;i++)
    {
        fact=fact*i;
    }
    cout<<fact<<endl;
    return 0;
}