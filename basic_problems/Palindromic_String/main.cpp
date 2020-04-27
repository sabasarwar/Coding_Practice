#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    string s;
    bool isPalindrome = true;
    
    cin>>s;
    
    for(int i=0; i<s.length()/2; i++) 
    {
        if(s[i] != s[s.length()-i-1])
            isPalindrome = false;
    }
    
    if(isPalindrome)
        cout<<"YES"<<"\n";
    else
        cout<<"NO"<<"\n";
}