/* ---------------------- Problem Statement -----------------------
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
---------------------------------------------------------------------*/

class Solution {
public:
    static bool sortbyfrequency(pair<char,int> &a, pair<char,int> &b)
    {
        return a.second>b.second;
    }
    
    string frequencySort(string s) 
    {
        unordered_map<char, int> _map;
        for(char c : s)
        {
            _map[c] += 1;
        }
        
        vector<pair<char,int>> count(_map.begin(), _map.end());
        
        sort(count.begin(), count.end(), sortbyfrequency);
        
        string result="";
        
        for(pair<char, int> p : count)
        {
            for(int i=0 ; i<p.second ; i++)
            {
                result += p.first;
            }
        }
        
        return result;
    }
};