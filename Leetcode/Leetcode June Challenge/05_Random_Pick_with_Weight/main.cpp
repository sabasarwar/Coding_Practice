/* ---------------------------------------- Problem Statement ------------------------------------

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:
1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.

Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]

Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
 
-------------------------------------------------------------------------------------------------*/

class Solution 
{
public:
    vector<int> cw;
    
    Solution(vector<int>& w) 
    {
        
        for (int i : w)
        {
            if(cw.empty())
                cw.push_back(i);
            else
                cw.push_back(i + cw.back());
        }
    }
    
    int pickIndex() 
    {
        int x = cw.back();
        int index = rand() % x;
        return binarySearch(index+1);
    }
    
    int binarySearch(int val)
    {
        int left = 0;
        int right = cw.size()-1;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(cw[mid] < val)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */