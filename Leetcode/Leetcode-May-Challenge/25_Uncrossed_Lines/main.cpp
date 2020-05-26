/* ---------------------- Problem Statement -----------------------
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

Example 1:

Input: A = [1,4,2], B = [1,2,4]
Output: 2

Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
---------------------------------------------------------------------*/

class Solution 
{
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) 
    {
        int m = A.size();
        int n = B.size();
        vector<vector<int>> mat(m+1, vector<int>(n+1, 0));
        for(int i=0; i<A.size(); i++) 
        {
            for(int j=0; j<B.size(); j++) 
            {
                if(A[i] == B[j])
                    mat[i+1][j+1] = 1 + mat[i][j];
                else
                    mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j]);
            }
        }
        
        return mat[A.size()][B.size()];
    }
};