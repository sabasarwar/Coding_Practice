/* ---------------------- Problem Statement -----------------------
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
---------------------------------------------------------------------*/

class Solution 
{
public:
    int findMaxLength(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return 0;
        
        unordered_map<int, int> _map;
        
        int maxlen = 0;
        int count = 0;
        _map[0] = -1;
        
        
        for(int i=0; i<nums.size(); i++) 
        {
            count = (nums[i] == 1) ? count + 1 : count - 1;
                
            if(_map.find(count) != _map.end()) 
            {
                maxlen = max(maxlen, i - _map[count]);
            } else {
                _map[count] = i;
            }
        }
        
        return maxlen;
    }
};