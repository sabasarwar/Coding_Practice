#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n;
    cin >> n;
    string str;
    cin >> str;
 
    bool flag = true;
 
    for(int i = 0; i < n - 1; i++) 
    {
        if(str[i] == 'H' && (str[i] == str[i + 1])) 
        {
            flag = false;
            break;
        }
    }
 
    if(!flag)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) 
        {
            if(str[i] == '.') 
            {
                cout << 'B';
            } else {
                cout << 'H';
            }
        }
        cout << endl;
    }
}