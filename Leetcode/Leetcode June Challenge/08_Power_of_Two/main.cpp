/* ---------------------------------------- Problem Statement ------------------------------------

Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1

Example 2:

Input: 16
Output: true
Explanation: 24 = 16

Example 3:

Input: 218
Output: false
 
-------------------------------------------------------------------------------------------------*/

// Simple solution

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n == 0)
        {
            return false;
        }
        while(n != 1)
        {
            if(n % 2 != 0)
            {
                return false;
            }
            else
            {
                n = n / 2;
            }
        }
        return true;
        
    }
};

// Solution using bit manipulation

class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        return n>0 && (n & (n-1))==0;
    }
};