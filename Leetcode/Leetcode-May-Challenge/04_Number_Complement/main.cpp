/* ---------------------- Problem Statement --------------------------
Given a positive integer, output its complement number. The complement 
strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), 
and its complement is 010. So you need to output 2.
---------------------------------------------------------------------*/

/* Solution 01 */

class Solution 
{
public:
    int findComplement(int num) 
    {
        if(num==0)
            return 1;
        
        int result=0;
        int pow=1;
        while(num>0)
        {
            result = result + (num%2 ^ 1) *pow;
            num >>=1; //num = num/2
            pow <<=1; //pow = pow*2
        }
        return result;
    }
};

/* Solution 01 */

class Solution 
{
public:
    int bitwiseComplement(int N) 
    {
        if(N==0)
            return 1;
        int bits=log2(N)+1;
        int mask=(unsigned)(pow(2,bits))-1;
        return N^mask; //XOR operation
    }
};