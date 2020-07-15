/* ----------------------------------- Problem Statement -------------------------------------
Rotate array by "d" elements using Juggling Algorithm : Inplace Method
Time Complexity : O(n*d)
Space Complexity : O(1)
---------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        int count[n];
        int res=0;
        
        for(int i=0 ; i<n ; i++)
        {
            count[i]=0;
            while(nums[i])
            {
                nums[i]=nums[i]/10;
                count[i]++;
            }
        }
        
        for(int j=0 ; j<n ; j++)
        {
            if(count[j]%2 == 0)
            {
                res++;
            }
        }
        
        return res;
    }
};

//Solution 02


class Solution {
public:
    int iseven(int a)
    {
        int c=0;
        while(a!=0){
            a=a/10;
            c++;
        }
        if(c%2==0)
            return 1;
        else return 0;
        
    }
    int findNumbers(vector<int>& nums) {
        int c=0,i;
        for(i=0;i<nums.size();i++)
            if(iseven(nums[i]))
                c++;
        return c;
    }
};