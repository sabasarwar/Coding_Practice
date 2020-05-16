/* ---------------------- Problem Statement -----------------------
Description: Given a circular array C of integers represented by A, find the 
maximum possible sum of a non-empty subarray of C.
Here, a circular array means the end of the array connects to the beginning of 
the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)
Also, a subarray may only include each element of the fixed buffer A at most once.  
(Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j 
 with k1 % A.length = k2 % A.length.)
 
Example 1:
Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:
Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
---------------------------------------------------------------------*/

int maxSubarraySumCircular(vector<int>& A) {
        int totalSum = 0;
        int maxEndAt = 0;
        int minEndAt = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        
        for(int el: A) {
            totalSum += el;
            maxEndAt = max(maxEndAt + el, el );
            maxSum = max(maxEndAt, maxSum);
            minEndAt = min(minEndAt + el, el );
            minSum = min(minEndAt, minSum);
        }
        
        if(maxSum > 0)
            return max(maxSum, totalSum - minSum);
        else return maxSum;
    }