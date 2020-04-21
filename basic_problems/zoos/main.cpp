#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    string str;
    cin>>str;

    char p[str.length()];
    for(int i=0 ; i<str.length() ; i++)
    {
        p[i]=str[i];
    }

    char element=p[0];
    int count=1;

    for(int j=1 ; j<str.length() ; j++)
    {
        if(p[j] == element)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    if((str.substr(count,str.length())).length() == count*2)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    return 0;
}
