/* ---------------------- Problem Statement -----------------------
We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]

Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
---------------------------------------------------------------------*/

class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int row = word1.size();
        int col = word2.size();
        
        vector<vector<int>> mat(row+1, vector<int>(col+1, 0));
        
        int costAdd, costDel, costTrans;
        
        for(int i=0; i<=row; i++) 
        {
            for(int j =0; j<=col; j++) 
            {
                if(i == 0)
                    mat[i][j] = j;
                
                else if(j == 0)
                    mat[i][j] = i;
                
                else 
                {
                    if(word1[i-1] == word2[j-1])
                        mat[i][j] = mat[i-1][j-1];
                    else
                        mat[i][j] = 1 + min({mat[i-1][j-1] , mat[i-1][j] , mat[i][j-1]});
                }
            }
        }
        return mat[row][col];
    }
};