/* ---------------------- Problem Statement -----------------------
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
---------------------------------------------------------------------*/

class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int result=-1;
        unordered_map<int,int> mp;
        for(int el : nums)
        {
            if(mp.find(el) == mp.end())
            {
                mp.insert(make_pair(el,1));
            }
            else
            {
                mp[el]+=1;
            }
        }
        
        for(int el : nums)
        {
            if(mp[el] > nums.size()/2)
                result=el;
        }
        return result;
    }
};