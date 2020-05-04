/* ----------------------- Problem Statement -----------------------------
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
 ---------------------------------------------------------------------------*/

/* Solution 1 */ 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
         if(nums.size() == 0)
            return 0;
         int s=1;
         for(int i=0 ; i<nums.size()-1 ; i++)
         {
             if(nums[i] != nums[i+1])
             {
                 nums[s]=nums[i+1];
                 s++;
             }
         }
         return s;
    }
};

/* Solution 2 */ 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        vector<int>::iterator it;
        it = nums.begin();
        
        int i=1;
        int item=nums[0];
        
        while(i<nums.size())
        {
            if(item == nums[i])
                nums.erase(it+i);
            else
                item=nums[i];
                i++;
        }
        return nums.size();
    }
};