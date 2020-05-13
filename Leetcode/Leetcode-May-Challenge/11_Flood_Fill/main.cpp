/* ---------------------- Problem Statement -----------------------
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2

Output: [[2,2,2],[2,2,0],[2,0,1]]

Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
---------------------------------------------------------------------*/

//Solution 01

class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int color=image[sr][sc];
        if(color == newColor)
            return image;
        fill(image, sr, sc, newColor, color);
        return image;
    }
    
    void fill(vector<vector<int>>& image, int r, int c, int curr, int prev)
    {
        if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != prev) return;
        image[r][c] = curr;
        fill(image, r+1, c, curr, prev);
        fill(image, r, c+1, curr, prev);
        fill(image, r-1, c, curr, prev);
        fill(image, r, c-1, curr, prev);
    }
};

//Solution 02

class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
    
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            int color = image[r][c];
            image[r][c] = newColor;
        
            if(r-1>=0)
            {
                if(image[r-1][c] != newColor and image[r-1][c] == color)
                {
                q.push({r-1,c});
                }
            }
            if(r+1 < n)
            {
                 if(image[r+1][c] != newColor and image[r+1][c] == color)
                 {
                q.push({r+1,c});
                 }
            }
            if(c-1>=0)
            {
                 if(image[r][c-1] != newColor and image[r][c-1] == color)
                 {
                q.push({r,c-1}); 
                 }
            }
            if(c+1<m)
            {
                 if(image[r][c+1] != newColor and image[r][c+1] == color)
                 {
                    q.push({r,c+1});
                 }
            }
         }
        
        return image;
    }
};