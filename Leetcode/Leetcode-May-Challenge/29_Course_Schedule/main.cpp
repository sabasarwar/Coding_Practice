/* ---------------------- Problem Statement -----------------------
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
---------------------------------------------------------------------*/

class Solution 
{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>list (numCourses, vector<int>());
        
        for(vector<int>& pre : prerequisites)
        {
            list[pre[0]].push_back(pre[1]);
        }
        
        vector<int> visited (numCourses, 0);
        
        for(int i=0 ; i<numCourses ; i++)
        {
            if(visited[i] == 0 && !dfs(list, visited, i))
                return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& list, vector<int>& visited, int v)
    {
        if(visited[v] == 1)
            return false;
        visited[v] = 1;
        
        for(int el : list[v])
        {
            if(!dfs(list, visited, el))
                return false;
        }
        
        visited[v] = 2;
        return true;
    }
};