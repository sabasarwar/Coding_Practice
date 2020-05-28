/* ---------------------- Problem Statement -----------------------
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
---------------------------------------------------------------------*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        vector<int> color (N,0);
        unordered_map<int,vector<int>> edges;
        
        for(auto item:dislikes)
        {
            edges[item[1]-1].push_back(item[0]-1);
            edges[item[0]-1].push_back(item[1]-1);
        }
        
        for(int i = 0; i<N;++i)
        {
            if(color[i]==0)
            {   
                int col = 1;  // color is 0 = not visited, 1 = red, 2 = blue
                color[i] = col;
                stack<int> s; 
                s.push(i);
                                
                while(!s.empty())
                {
                    int t = s.top(); s.pop();
                    col = (color[t]==1)?2:1;
                    for(auto elem:edges[t])
                    {
                        if(color[elem] == 0)
                        {   color[elem] = col;
                            s.push(elem);
                        }
                        else if (color[elem]!=col)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
