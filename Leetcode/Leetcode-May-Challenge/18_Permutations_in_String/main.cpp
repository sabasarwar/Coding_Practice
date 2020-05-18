/* ---------------------- Problem Statement -----------------------

Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
 
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
---------------------------------------------------------------------*/

//Array

class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {        
        int m = (int)s1.size();
        int n = (int)s2.size();
        if (n < m) 
            return false;
        
        vector<int> a(26,0);
        vector<int> b(26,0);
        
        for (int i=0;i<s1.size();i++)
        {
            a[s1[i] - 'a'] ++;
            b[s2[i] - 'a'] ++;
        }
        
        for (int i=m;i<n;i++)
        {
            if (a == b)
            {
                return true;
            }
            
            b[s2[i- m] - 'a' ] --;
            b[s2[i] - 'a']++;
        }
        
        if (a == b) 
            return true;
        return false;
    }
};

//HashMap

class Solution 
{
public:
    bool checkInclusion(string s1, string s2) 
    {
         if(s1.size() > s2.size())
             return false;
         int start=0;
         int count=0;
         unordered_map<char, int> _map;
         for(auto c : s1)
         {
             _map[c]++;
         }
        
         for(int i=0 ; i<s2.size() ; i++)
         {
             char a=s2[i];
             if(_map.find(a) != _map.end())
             {
                 _map[a]--;
                 if(_map[a] == 0)
                 {
                      count++;
                 }            
             }
            
             if(count == _map.size())
                 return true;
            
             if(i>= s1.size()-1)
             {
                 char b=s2[start++];
                 if(_map.find(b) != _map.end())
                 {
                     if(_map[b] == 0)
                     {
                         count--;
                     }
                    
                     _map[b]++;
                 }
             }
         }
         return false;
    }
};