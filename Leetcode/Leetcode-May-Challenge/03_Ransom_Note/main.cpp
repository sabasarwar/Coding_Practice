/* ---------------------- Problem Statement -----------------------
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
---------------------------------------------------------------------*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> mp;
        for(char ch : magazine)
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
        
        for(char ch : ransomNote)
        {
            int count=mp[ch];
            if(mp.find(ch) == mp.end())
                return false;
            if(count == 0)
                return false;
            mp[ch]=count-1;
        }
        
        return true;
    }
};