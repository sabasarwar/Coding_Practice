/* ---------------------- Problem Statement --------------------------
Given a string, find the first non-repeating character in it and return 
it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
---------------------------------------------------------------------*/

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        if(s.length() == 0)
            return -1;

        unordered_map<char, int> mp;
        for(char ch : s)
        {
            if(mp.find(ch) == mp.end())
            {
                mp.insert(make_pair(ch,1));
            }
            else
            {
                mp[ch]+=1;
            }
        }
        
        int i=0;
        
        for(char ch : s)
        {
            if(mp[ch] == 1)
                return i;
            i++;
        }
        
        return -1;
    }
};