/* ---------------------- Problem Statement -----------------------
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
 * 
---------------------------------------------------------------------*/

/* Solution in O(n^2) */

class Solution 
{
    public:
    int numJewelsInStones(string J, string S) 
    {
        int count=0;
        char jewel[J.length()];
        for(int i=0 ; i<sizeof(jewel) ; i++)
        {
            jewel[i]=J[i];
        }
        
        char stone[S.length()];
        for(int j=0 ; j<sizeof(stone) ; j++)
        {
            stone[j]=S[j];
        }
        
        for(int a=0 ; a<sizeof(jewel) ; a++)
        {
            for(int b=0 ; b<sizeof(stone) ; b++)
            {
                if(jewel[a] == stone[b])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

/* Solution in O(n) */

int numJewelsInStones(string J, string S) 
{
        
        if(J.length() == 0 || S.length() == 0)
            return 0;
        
        unordered_set<char> jewel;
        int result = 0;
        for(char ch: J)
            jewel.insert(ch);
        
        for(char ch: S)
        {
             if(jewel.find(ch) != jewel.end())
                result++;
        }
        
        return result;
    }
