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

/* Solution 01 - Array */

struct ComparePoints
{
    bool operator()(const vector<int>& p1, const vector<int>& p2)
    {
        return (p1[0]*p1[0] + p1[1]*p1[1]) < (p2[0]*p2[0] + p2[1]*p2[1]);
    }
};


class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        sort(points.begin(), points.end(), ComparePoints());
        vector<vector<int>> result;
        for(int i=0 ; i<K ; i++)
        {
            result.push_back(points[i]);
        }
        
        return result;
    }
};

/* Solution 02 - Maxheap */

class Solution {
    
public:
    int findDistance(vector<int> point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<pair<int,int>> maxHeap;
        vector<vector<int>> result;
        int distance;
        for(int i=0;i<points.size(); i++)
        {
            distance = findDistance(points[i]);
            if(i<K)
            {
                maxHeap.push({distance, i});
            }
            else if(distance < maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push({distance, i});
            }
        }
        while(!maxHeap.empty())
        {
            cout<<maxHeap.top().first<<" "<<maxHeap.top().second<<endl;
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }
        return result;
    }
};