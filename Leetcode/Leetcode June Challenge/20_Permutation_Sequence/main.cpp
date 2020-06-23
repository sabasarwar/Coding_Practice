/* ---------------------------------------- Problem Statement ------------------------------------
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
 
Example 1:

Input: n = 3, k = 3
Output: "213"

Example 2:

Input: n = 4, k = 9
Output: "2314"
-------------------------------------------------------------------------------------------------*/

class Solution 
{
public:
   vector<int> fact;
    
    void findfact(int n)
    {
        fact = vector<int>(n);
        
        fact[0] = 1;
        
        if(n==1) return;
        
        fact[1] = 1;
        for(int i=2; i<n; i++)
            fact[i] = i*fact[i-1];
    }
    
    string getPermutation(int N, int K) {
        int n = N-1, k = K-1, nt, kt;
        
        findfact(N);
        vector<int> num(N);
        for(int i=0; i<N; i++)
            num[i] = i+1;
        vector<int>::iterator it; 
        
        string ans = "";
        
        while(n>=0)
        {
            nt = k/fact[n];
            kt = k%fact[n];

            ans += (num[nt]+'0');
            it = num.begin(); 
            num.erase(it+nt);
            n--;
            k = kt;   
        }

        return ans;
    }
};