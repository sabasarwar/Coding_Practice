/* ---------------------- Problem Statement -----------------------
You are given an array coordinates, coordinates[i] = [x, y], where 
[x, y] represents the coordinate of a point. Check if these points 
make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
---------------------------------------------------------------------*/

#define MAX_VAL 100000
class Solution {
public:
    
    double find_slope(vector<int>& c1, vector<int>&c2)
    {
        if(c1[0] == c2[0])
            return MAX_VAL;
        return (double)(c2[1]-c1[1])/(c2[0]-c1[0]);
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        double m=find_slope(coordinates[0], coordinates[1]);
        for(int i=2 ; i<coordinates.size() ; i++)
        {
            double d=find_slope(coordinates[i], coordinates[0]);
            if(d!=m)
                return false;
        }
        return true;
    }
};